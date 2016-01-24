#include "HelloWorldScene.h"

USING_NS_CC;

using namespace ui;

float goUp = 0;
bool touch = false; 


Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	auto winSize = Director::getInstance()->getWinSize();

	spriteName = Sprite::create("girl.png");
	spriteName->setPosition(Vec2(winSize.width/2,winSize.height/2));
	this->addChild(spriteName);


	auto button = Button::create("Button.png", "ButtonPressed.png", "ButtonPressed.png");
	button->setTitleText("Jump");
	button->setTitleFontName("MarkerFelt.ttf");
	button->setTitleFontSize(12.0f);
	button->setPosition(Vec2(winSize.width/2, winSize.height/2 - 100));

	button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
	{
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			touch = true;
			break;
		case cocos2d::ui::Widget::TouchEventType::MOVED:	
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			touch = false;
			break;
		case cocos2d::ui::Widget::TouchEventType::CANCELED:
			break;
		default:
			break;
		}
	});

	this->addChild(button);

	scheduleUpdate();

    return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::update(float dt)
{
	auto winSize = Director::getInstance()->getWinSize();

	if(touch == true)
	{
		goUp += 3.0f;
	}

	if(touch == false && goUp > 0)
	{
		goUp -= 3.0f;
	}

	spriteName->setPosition(Vec2(winSize.width/2,winSize.height/2 + goUp));
}