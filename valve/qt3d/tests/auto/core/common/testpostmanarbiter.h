/****************************************************************************
**
** Copyright (C) 2015 Klaralvdalens Datakonsult AB (KDAB).
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL-EXCEPT$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <Qt3DCore/private/qpostman_p.h>
#include <Qt3DCore/private/qchangearbiter_p.h>

QT_BEGIN_NAMESPACE

namespace Qt3DCore {
    class QNode;
} // Qt3D

class TestArbiter;

class TestPostman : public Qt3DCore::QAbstractPostman
{
public:
    explicit TestPostman(TestArbiter *arbiter);
    void sceneChangeEvent(const Qt3DCore::QSceneChangePtr &) final;
    void setScene(Qt3DCore::QScene *) final;
    void notifyBackend(const Qt3DCore::QSceneChangePtr &e) final;
    bool shouldNotifyFrontend(const Qt3DCore::QSceneChangePtr &e) final;

private:
    TestArbiter *m_arbiter;
};

class TestArbiter : public Qt3DCore::QAbstractArbiter
{
public:
    TestArbiter();
    ~TestArbiter();

    void sceneChangeEvent(const Qt3DCore::QSceneChangePtr &e) final;

    void sceneChangeEventWithLock(const Qt3DCore::QSceneChangePtr &e) final;

    void sceneChangeEventWithLock(const Qt3DCore::QSceneChangeList &e) final;

    Qt3DCore::QAbstractPostman *postman() const final;

    QVector<Qt3DCore::QSceneChangePtr> events;
    QVector<Qt3DCore::QNode *> dirtyNodes;
    QVector<Qt3DCore::NodeRelationshipChange> dirtySubNodes;

    void setArbiterOnNode(Qt3DCore::QNode *node);
    void addDirtyFrontEndNode(Qt3DCore::QNode *node) final;
    QT_WARNING_PUSH
    QT_WARNING_DISABLE_DEPRECATED
    void addDirtyFrontEndNode(Qt3DCore::QNode *node, Qt3DCore::QNode *subNode, const char *property, Qt3DCore::ChangeFlag change) final;
    QT_WARNING_POP
    void removeDirtyFrontEndNode(Qt3DCore::QNode *node) final;

private:
    TestPostman *m_postman;
};

QT_END_NAMESPACE
