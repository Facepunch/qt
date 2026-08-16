#ifdef _WIN32
#include <Windows.h>
#else
// s&box: POSIX port. dlsym on RTLD_DEFAULT searches every object already loaded into the
// process, which is where tier0 will be by the time Qt initialises - the equivalent of
// GetModuleHandle + GetProcAddress on Windows.
#include <dlfcn.h>
#endif // _WIN32

#include <cstdlib>

#ifdef _WIN32
// Disable warning: initializers put in library initialization area
#pragma warning(disable:4073)
#pragma init_seg(lib)
#endif

typedef void *( *QAlloc_t )( size_t );
typedef void ( *QFree_t )( void * );
typedef void *( *QRealloc_t)(void *, size_t );

QAlloc_t s_pAlloc = &malloc;
QRealloc_t s_pRealloc = &realloc;
QFree_t s_pFree = &free;

typedef void ( *QGetCustomAllocators_t)( QAlloc_t *pAlloc, QFree_t *pFree, QRealloc_t *pRealloc );

static int install_custom_allocators()
{
#ifdef _WIN32
	HMODULE appModule = GetModuleHandleA( "tier0.dll" );
	QGetCustomAllocators_t pGetCustomAllocators = (QGetCustomAllocators_t)GetProcAddress( appModule, "Qt_GetCustomAllocators" );
#else
	QGetCustomAllocators_t pGetCustomAllocators = (QGetCustomAllocators_t)dlsym( RTLD_DEFAULT, "Qt_GetCustomAllocators" );
#endif
	if ( pGetCustomAllocators )
	{
		pGetCustomAllocators( &s_pAlloc, &s_pFree, &s_pRealloc );
	}

	return 1;
}

#ifdef _WIN32
// init_seg(lib) above orders this ahead of ordinary static initialisers.
static int qt_force_install_custom_allocators = install_custom_allocators();
#else
// The GCC equivalent of init_seg(lib): a low priority number runs early, before any
// static initialiser that might allocate.
__attribute__( ( constructor( 101 ) ) )
static void qt_force_install_custom_allocators()
{
	install_custom_allocators();
}
#endif

void *operator new[]( size_t size )
{
	return s_pAlloc( size );
}

void *operator new( size_t size )
{
	return s_pAlloc( size );
}

void operator delete[]( void *ptr )
{
	s_pFree( ptr );
}

void operator delete[]( void *ptr, size_t )
{
	s_pFree( ptr );
}

void operator delete( void *ptr )
{
	s_pFree( ptr );
}

void operator delete( void *ptr, size_t )
{
	s_pFree( ptr );
}
