#include "cocos2d.h"
#include "GalGameScene.h"

USING_NS_CC;

int main(int argc, char* argv[]) {
    AppDelegate app;
    return Application::getInstance()->run();
}

class AppDelegate : public Application {
public:
    virtual bool applicationDidFinishLaunching() {
        auto director = Director::getInstance();
        auto glview = director->getOpenGLView();
        if (!glview) {
            glview = GLViewImpl::create("GalGame Engine");
            glview->setFrameSize(1280, 720);
            director->setOpenGLView(glview);
        }

        director->setAnimationInterval(1.0f / 60.0f);

        auto scene = GalGameScene::createScene();
        director->runWithScene(scene);

        return true;
    }

    virtual void applicationDidEnterBackground() {
        Director::getInstance()->pause();
    }

    virtual void applicationWillEnterForeground() {
        Director::getInstance()->resume();
    }
};