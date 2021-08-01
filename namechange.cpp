#include "namechange.h"

NameChange::NameChange()
{

}

void NameChange::ChangePostfix(QStringList paths,std::string newPostfix)
{
    for(int i{0};i<paths.size();i++)
    {
        std::string oldName = paths[i].toStdString();
        std::string filename = oldName.substr(0,oldName.find_last_of(".")+1);
        std::string newName = filename + newPostfix;


        QString Q_newName = QString::fromStdString(newName);
        qDebug()<<"newName: "<<Q_newName;

        QString Q_oldName = QString::fromStdString(oldName);
        qDebug()<<"oldName: "<<Q_oldName;

        QFile::rename(Q_oldName, Q_newName);
    }
}
