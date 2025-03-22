#include "json_plugin.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QString>
#include <iostream>

JsonPlugin::JsonPlugin() {
    tabWidget = new QWidget();
    auto* layout = new QVBoxLayout(tabWidget);

    QTextEdit* textEdit = new QTextEdit();
    textEdit->setReadOnly(true);

    // Example JSON visualization of system tree data
    QJsonObject sysTree;
    sysTree["name"] = "root";
    sysTree["children"] = QJsonArray::fromStringList({"node1", "node2", "node3"});

    QJsonDocument doc(sysTree);
    textEdit->setText(doc.toJson(QJsonDocument::Indented));

    layout->addWidget(textEdit);
    tabWidget->setLayout(layout);
}

void JsonPlugin::cubeOpened(cubepluginapi::PluginServices* service) {
    service->addTab(cubepluginapi::SYSTEM, tabWidget);
}
