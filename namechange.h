#ifndef NAMECHANGE_H
#define NAMECHANGE_H
#include <string>
#include <QStringList>
#include <QDebug>
#include <QFile>

class NameChange
{
public:
    NameChange();
    void ChangePostfix(QStringList paths,std::string newPostfix);
};

#endif // NAMECHANGE_H
