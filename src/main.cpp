#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include "../includes/includes/notif.hpp"

using namespace geode::prelude;

class $modify(PlayLayer) {
    void showNewBest(bool newReward, int orbs, int diamonds, bool demonKey, bool noRetry, bool noTitle) {
        if (Mod::get()->getSettingValue<bool>("replace-new-best")) {
            auto icon = CCSprite::create(geode::utils::string::pathToString(Mod::get()->getResourcesDir() / "just.png").c_str());
            notifapi::fnotif("New Best! " + std::to_string((int)(m_level->m_normalPercent)) + "%", "warning", 3.0f, {0,0,0}, 1.0f, notifapi::Position::TopRight, notifapi::Animation::Slide, "", 1.0f, icon);
        } else {
            PlayLayer::showNewBest(newReward, orbs, diamonds, demonKey, noRetry, noTitle);
        }
    }
};
