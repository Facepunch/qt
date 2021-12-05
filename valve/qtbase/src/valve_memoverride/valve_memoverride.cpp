#ifdef _WIN32
#include <Windows.h>
#else
#error Need to implement memoverride for Qt on non-win32 platforms or decide it's not needed
#endif // _WIN32

#include <cstdlib>

#ifdef _WIN32
// Disable warning: initializers put in library initialization area
#pragma warning(disable:4073)
#pragma init_seg(lib)
#else
#pragma error( "Error: static object initialization order is not guaranteed!" );
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
	HMODULE appModule = GetModuleHandleA( "tier0.dll" );
	QGetCustomAllocators_t pGetCustomAllocators = (QGetCustomAllocators_t)GetProcAddress( appModule, "Qt_GetCustomAllocators" );
	if ( pGetCustomAllocators )
	{
		pGetCustomAllocators( &s_pAlloc, &s_pFree, &s_pRealloc );
	}

	return 1;
}

static int qt_force_install_custom_allocators = install_custom_allocators();

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
