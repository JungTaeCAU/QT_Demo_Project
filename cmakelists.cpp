#include "cmakelists.h"
#include <QTextStream>

CMakeLists::CMakeLists()
{

}

void CMakeLists::SetProjectName(const QString & name)
{
    projectName = name;
}

void CMakeLists::AddCMakeFlags(const QString & key, const QString & value)
{
    cmakeFlags.insert(key,value);
}

void CMakeLists::AddDefine(const QString & value)
{
    defines.append(value);
}

void CMakeLists::AddIncludeDirectory(const QString & dir)
{
    includeDirectories.append(dir);
}

void CMakeLists::AddSource(const QString & key, const QString & value)
{
    sources.insert(key,value);
}

QString CMakeLists::GenerateCMakeLists()
{
    QString outputString;
    QTextStream ots(&outputString);

    ots << "cmake_minimum_required(VERSION 3.10)" << Qt::endl;
    ots << QString("project (%1)").arg(projectName) << Qt::endl;

    for(const auto& e: cmakeFlags.keys()){
        ots << QString("set (%1 %2)").arg(e, cmakeFlags.value(e)) << Qt::endl;
    }

    if(defines.size() > 0){
        QString def = "";
        for(const auto& e: defines){
            def += "-D" + e + " ";
        }
        ots << QString("add_definitions(%1)").arg(def) << Qt::endl;
    }
    // target_include_directories(Tutorial PUBLIC
    //"${PROJECT_BINARY_DIR}"

    for(const auto& e: includeDirectories){
        ots << QString("target_include_directories(%1)").arg(e) << Qt::endl;
    }

    for(const auto& e: sources.keys()){
        ots << QString("add_executable(%1 %2)").arg(e, sources.value(e)) << Qt::endl;
    }


    return outputString;
}
