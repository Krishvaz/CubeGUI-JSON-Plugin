#pragma once
#include <CubePlugin.h>
#include <QWidget>

class JsonPlugin : public cubepluginapi::CubePlugin {
    Q_OBJECT
public:
    JsonPlugin();
    ~JsonPlugin() override = default;
    void cubeOpened(cubepluginapi::PluginServices* service) override;

private:
    QWidget* tabWidget;
};

extern "C" cubepluginapi::CubePlugin* createPlugin() {
    return new JsonPlugin();
}
