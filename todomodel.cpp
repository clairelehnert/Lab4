#include "todomodel.h"
#include <QFile>
#include <iostream>
#include <QMessageBox>
#include <QTextStream>

ToDoModel::ToDoModel(QObject *parent)
    :QAbstractTableModel(parent)
{

}

int ToDoModel::rowCount(const QModelIndex &parent) const
{
    return items.size();
}

int ToDoModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QVariant ToDoModel::data(const QModelIndex &index, int role) const
{
    if (role==Qt:: DisplayRole){

        switch(index.column()){
        case 0: return items.at(index.row());
        }
    }

    return QVariant();
}

void ToDoModel::openFile(QString filePath)
{

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
        return;
    }


    QTextStream in (&file);

    items.clear();

    while (!in.atEnd()) {
        QString line= in.readLine();
        QStringList fields= line.split (",");

        for (int j=0; j< fields.length(); j++){
            std::cout<< "["<< j<< "]"<< fields[j].toStdString();

        }
        std::cout<< std:: endl;

        items.push_back(fields[0]);
    }
    file.close();
    emit layoutChanged();
}
