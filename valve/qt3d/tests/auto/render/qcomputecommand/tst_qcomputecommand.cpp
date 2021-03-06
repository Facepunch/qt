/****************************************************************************
**
** Copyright (C) 2016 Paul Lemire <paul.lemire350@gmail.com>
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


#include <QtTest/QTest>
#include <Qt3DRender/qcomputecommand.h>
#include <Qt3DRender/private/qcomputecommand_p.h>
#include <QObject>
#include <QSignalSpy>
#include <Qt3DCore/private/qnodecreatedchangegenerator_p.h>
#include <Qt3DCore/qnodecreatedchange.h>
#include "testpostmanarbiter.h"

class tst_QComputeCommand : public QObject
{
    Q_OBJECT

private Q_SLOTS:

    void checkDefaultConstruction()
    {
        // GIVEN
        Qt3DRender::QComputeCommand computeCommand;

        // THEN
        QCOMPARE(computeCommand.workGroupX(), 1);
        QCOMPARE(computeCommand.workGroupY(), 1);
        QCOMPARE(computeCommand.workGroupZ(), 1);
        QCOMPARE(computeCommand.runType(), Qt3DRender::QComputeCommand::Continuous);
    }

    void checkPropertyChanges()
    {
        // GIVEN
        Qt3DRender::QComputeCommand computeCommand;

        {
            // WHEN
            QSignalSpy spy(&computeCommand, SIGNAL(workGroupXChanged()));
            const int newValue = 128;
            computeCommand.setWorkGroupX(newValue);

            // THEN
            QVERIFY(spy.isValid());
            QCOMPARE(computeCommand.workGroupX(), newValue);
            QCOMPARE(spy.count(), 1);

            // WHEN
            spy.clear();
            computeCommand.setWorkGroupX(newValue);

            // THEN
            QCOMPARE(computeCommand.workGroupX(), newValue);
            QCOMPARE(spy.count(), 0);
        }
        {
            // WHEN
            QSignalSpy spy(&computeCommand, SIGNAL(workGroupYChanged()));
            const int newValue = 256;
            computeCommand.setWorkGroupY(newValue);

            // THEN
            QVERIFY(spy.isValid());
            QCOMPARE(computeCommand.workGroupY(), newValue);
            QCOMPARE(spy.count(), 1);

            // WHEN
            spy.clear();
            computeCommand.setWorkGroupY(newValue);

            // THEN
            QCOMPARE(computeCommand.workGroupY(), newValue);
            QCOMPARE(spy.count(), 0);
        }
        {
            // WHEN
            QSignalSpy spy(&computeCommand, SIGNAL(workGroupZChanged()));
            const int newValue = 512;
            computeCommand.setWorkGroupZ(newValue);

            // THEN
            QVERIFY(spy.isValid());
            QCOMPARE(computeCommand.workGroupZ(), newValue);
            QCOMPARE(spy.count(), 1);

            // WHEN
            spy.clear();
            computeCommand.setWorkGroupZ(newValue);

            // THEN
            QCOMPARE(computeCommand.workGroupZ(), newValue);
            QCOMPARE(spy.count(), 0);
        }
        {
            // WHEN
            QSignalSpy spy(&computeCommand, SIGNAL(runTypeChanged()));
            const Qt3DRender::QComputeCommand::RunType newValue = Qt3DRender::QComputeCommand::Manual;
            computeCommand.setRunType(newValue);

            // THEN
            QVERIFY(spy.isValid());
            QCOMPARE(computeCommand.runType(), newValue);
            QCOMPARE(spy.count(), 1);

            // WHEN
            spy.clear();
            computeCommand.setRunType(newValue);

            // THEN
            QCOMPARE(computeCommand.runType(), newValue);
            QCOMPARE(spy.count(), 0);
        }
    }

    void checkCreationData()
    {
        // GIVEN
        Qt3DRender::QComputeCommand computeCommand;

        computeCommand.setWorkGroupX(128);
        computeCommand.setWorkGroupY(512);
        computeCommand.setWorkGroupZ(1024);
        computeCommand.setRunType(Qt3DRender::QComputeCommand::Manual);

        // WHEN
        QVector<Qt3DCore::QNodeCreatedChangeBasePtr> creationChanges;

        {
            Qt3DCore::QNodeCreatedChangeGenerator creationChangeGenerator(&computeCommand);
            creationChanges = creationChangeGenerator.creationChanges();
        }

        // THEN
        {
            QCOMPARE(creationChanges.size(), 1);

            const auto creationChangeData = qSharedPointerCast<Qt3DCore::QNodeCreatedChange<Qt3DRender::QComputeCommandData>>(creationChanges.first());
            const Qt3DRender::QComputeCommandData cloneData = creationChangeData->data;

            QCOMPARE(computeCommand.workGroupX(), cloneData.workGroupX);
            QCOMPARE(computeCommand.workGroupY(), cloneData.workGroupY);
            QCOMPARE(computeCommand.workGroupZ(), cloneData.workGroupZ);
            QCOMPARE(computeCommand.runType(), cloneData.runType);
            QCOMPARE(0, cloneData.frameCount);
            QCOMPARE(computeCommand.id(), creationChangeData->subjectId());
            QCOMPARE(computeCommand.isEnabled(), true);
            QCOMPARE(computeCommand.isEnabled(), creationChangeData->isNodeEnabled());
            QCOMPARE(computeCommand.metaObject(), creationChangeData->metaObject());
        }

        // WHEN
        computeCommand.setEnabled(false);

        {
            Qt3DCore::QNodeCreatedChangeGenerator creationChangeGenerator(&computeCommand);
            creationChanges = creationChangeGenerator.creationChanges();
        }

        // THEN
        {
            QCOMPARE(creationChanges.size(), 1);

            const auto creationChangeData = qSharedPointerCast<Qt3DCore::QNodeCreatedChange<Qt3DRender::QComputeCommandData>>(creationChanges.first());
            const Qt3DRender::QComputeCommandData cloneData = creationChangeData->data;

            QCOMPARE(computeCommand.workGroupX(), cloneData.workGroupX);
            QCOMPARE(computeCommand.workGroupY(), cloneData.workGroupY);
            QCOMPARE(computeCommand.workGroupZ(), cloneData.workGroupZ);
            QCOMPARE(computeCommand.id(), creationChangeData->subjectId());
            QCOMPARE(computeCommand.isEnabled(), false);
            QCOMPARE(computeCommand.runType(), cloneData.runType);
            QCOMPARE(0, cloneData.frameCount);
            QCOMPARE(computeCommand.isEnabled(), creationChangeData->isNodeEnabled());
            QCOMPARE(computeCommand.metaObject(), creationChangeData->metaObject());
        }
    }

    void checkWorkGroupXUpdate()
    {
        // GIVEN
        TestArbiter arbiter;
        Qt3DRender::QComputeCommand computeCommand;
        arbiter.setArbiterOnNode(&computeCommand);

        {
            // WHEN
            computeCommand.setWorkGroupX(256);
            QCoreApplication::processEvents();

            // THEN
            QCOMPARE(arbiter.events.size(), 0);
            QCOMPARE(arbiter.dirtyNodes.size(), 1);
            QCOMPARE(arbiter.dirtyNodes.front(), &computeCommand);

            arbiter.dirtyNodes.clear();
        }

        {
            // WHEN
            computeCommand.setWorkGroupX(256);
            QCoreApplication::processEvents();

            // THEN
            QCOMPARE(arbiter.dirtyNodes.size(), 0);
        }

    }

    void checkWorkGroupYUpdate()
    {
        // GIVEN
        TestArbiter arbiter;
        Qt3DRender::QComputeCommand computeCommand;
        arbiter.setArbiterOnNode(&computeCommand);

        {
            // WHEN
            computeCommand.setWorkGroupY(512);

            // THEN
            QCOMPARE(arbiter.events.size(), 0);
            QCOMPARE(arbiter.dirtyNodes.size(), 1);
            QCOMPARE(arbiter.dirtyNodes.front(), &computeCommand);

            arbiter.dirtyNodes.clear();
        }

        {
            // WHEN
            computeCommand.setWorkGroupY(512);

            // THEN
            QCOMPARE(arbiter.events.size(), 0);
            QCOMPARE(arbiter.dirtyNodes.size(), 0);
        }

    }

    void checkWorkGroupZUpdate()
    {
        // GIVEN
        TestArbiter arbiter;
        Qt3DRender::QComputeCommand computeCommand;
        arbiter.setArbiterOnNode(&computeCommand);

        {
            // WHEN
            computeCommand.setWorkGroupZ(64);
            QCoreApplication::processEvents();

            // THEN
            QCOMPARE(arbiter.events.size(), 0);
            QCOMPARE(arbiter.dirtyNodes.size(), 1);
            QCOMPARE(arbiter.dirtyNodes.front(), &computeCommand);

            arbiter.dirtyNodes.clear();
        }

        {
            // WHEN
            computeCommand.setWorkGroupZ(64);
            QCoreApplication::processEvents();

            // THEN
            QCOMPARE(arbiter.events.size(), 0);
            QCOMPARE(arbiter.dirtyNodes.size(), 0);
        }

    }

    void checkRunTypeUpdate()
    {
        // GIVEN
        TestArbiter arbiter;
        Qt3DRender::QComputeCommand computeCommand;
        arbiter.setArbiterOnNode(&computeCommand);

        {
            // WHEN
            computeCommand.setRunType(Qt3DRender::QComputeCommand::Manual);
            QCoreApplication::processEvents();

            // THEN
            QCOMPARE(arbiter.events.size(), 0);
            QCOMPARE(arbiter.dirtyNodes.size(), 1);
            QCOMPARE(arbiter.dirtyNodes.front(), &computeCommand);

            arbiter.dirtyNodes.clear();
        }

        {
            // WHEN
            computeCommand.setRunType(Qt3DRender::QComputeCommand::Manual);
            QCoreApplication::processEvents();

            // THEN
            QCOMPARE(arbiter.events.size(), 0);
            QCOMPARE(arbiter.dirtyNodes.size(), 0);
        }
    }

    void checkTrigger()
    {
        // GIVEN
        TestArbiter arbiter;
        Qt3DRender::QComputeCommand computeCommand;
        arbiter.setArbiterOnNode(&computeCommand);
        computeCommand.setRunType(Qt3DRender::QComputeCommand::Manual);
        computeCommand.setEnabled(false);
        QCoreApplication::processEvents();
        arbiter.events.clear();

        {
            // WHEN
            computeCommand.trigger(1);
            QCoreApplication::processEvents();

            // THEN
            QCOMPARE(arbiter.events.size(), 0);
            QCOMPARE(arbiter.dirtyNodes.size(), 1);
            QCOMPARE(arbiter.dirtyNodes.front(), &computeCommand);
            QCOMPARE(computeCommand.isEnabled(), true);

            computeCommand.setEnabled(false);
            QCoreApplication::processEvents();
            arbiter.dirtyNodes.clear();
        }

        {
            // WHEN
            computeCommand.trigger(2);
            QCoreApplication::processEvents();

            // THEN
            QCOMPARE(arbiter.events.size(), 0);
            QCOMPARE(arbiter.dirtyNodes.size(), 1);
            QCOMPARE(arbiter.dirtyNodes.front(), &computeCommand);
            QCOMPARE(computeCommand.isEnabled(), true);

            computeCommand.setEnabled(false);
            QCoreApplication::processEvents();
            arbiter.events.clear();
            arbiter.dirtyNodes.clear();
        }

        {
            // WHEN
            computeCommand.trigger(10, 11, 12, 1);
            QCoreApplication::processEvents();

            // THEN
            QCOMPARE(arbiter.events.size(), 0);
            QCOMPARE(arbiter.dirtyNodes.size(), 1);
            QCOMPARE(arbiter.dirtyNodes.front(), &computeCommand);
            QCOMPARE(computeCommand.isEnabled(), true);
            QCOMPARE(computeCommand.workGroupX(), 10);
            QCOMPARE(computeCommand.workGroupY(), 11);
            QCOMPARE(computeCommand.workGroupZ(), 12);

            computeCommand.setEnabled(false);
            arbiter.dirtyNodes.clear();
        }
    }

};

QTEST_MAIN(tst_QComputeCommand)

#include "tst_qcomputecommand.moc"
