/*
 * Copyright (C) 2020 ~ 2021 Uniontech Software Technology Co., Ltd.
 *
 * Author:     lanxuesong<luzhen@uniontech.com>
 *
 * Maintainer: lanxuesong<zhengyouge@uniontech.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <gtest/gtest.h>
#include <sanitizer/asan_interface.h>

#include <QDebug>
#include <QApplication>
#include <QProcess>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    qInfo() << "start test cases ..............";

    ::testing::InitGoogleTest(&argc, argv);

    int ret = RUN_ALL_TESTS();

    qInfo() << "end test cases ..............";

#ifdef ENABLE_TSAN_TOOL
    __sanitizer_set_report_path("../../asan_util_dfm.log");
#endif

    return ret;
}
