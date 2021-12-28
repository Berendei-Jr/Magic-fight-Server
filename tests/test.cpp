#include <stdexcept>
#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "../include/board.h"



TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
}

TEST(board, test1){
    EXPECT_NO_THROW(board B(3));
}

TEST(hero, test1){
    board B(3);
    ActionsList hero_actions[4];
    hero_actions[0]=Step;
    hero_actions[1]=Fireball;
    hero_actions[2]=Leap;
    hero_actions[3]=Wizard;
    sf::Texture hero_texture;
    hero H(B.center, hero_texture, hero_actions, 1);
    int* a = H.position->GetCoordinate();
    EXPECT_EQ(a[0], 0);
    EXPECT_EQ(a[1], 0);
}

TEST(move, test1){
    board B(3);
    ActionsList hero_actions[4];
    hero_actions[0]=Step;
    hero_actions[1]=Fireball;
    hero_actions[2]=Leap;
    hero_actions[3]=Wizard;
    sf::Texture hero_texture;
    hero H(B.center, hero_texture, hero_actions, 1);
    H.make_action(0, 0);
    int* a = H.position->GetCoordinate();
    EXPECT_EQ(a[0], -1);
    EXPECT_EQ(a[1], 0);
}


TEST(fireball, test1){
    board B(3);
    ActionsList hero_actions[4];
    hero_actions[0]=Step;
    hero_actions[1]=Fireball;
    hero_actions[2]=Leap;
    hero_actions[3]=Wizard;
    sf::Texture hero_texture;
    hero_texture.loadFromFile("/home/supsun/Documents/Magic_fight/img/hero.png");
    hero H(B.center, hero_texture, hero_actions, 1);
    EXPECT_NO_THROW(H.make_action(1, 0));
}

TEST(fireball, test2){
    board B(3);
    ActionsList hero_actions[4];
    hero_actions[0]=Step;
    hero_actions[1]=Fireball;
    hero_actions[2]=Leap;
    hero_actions[3]=Wizard;
    sf::Texture hero_texture;
    hero_texture.loadFromFile("/home/supsun/Documents/Magic_fight/img/hero.png");
    hero H0(B.center, hero_texture, hero_actions, 1);
    hero H1(B.center, hero_texture, hero_actions, 1);
    H0.make_action(0, 0);
    H0.make_action(0, 0);
    H0.make_action(1, 3);
    sf::Time duration = sf::seconds(1);
    B.Tick();
    sf::sleep(duration);
    B.Tick();
    sf::sleep(duration);
    B.Tick();
    EXPECT_EQ(H1.health, 50);

}

TEST(mana, test1){
    board B(3);
    ActionsList hero_actions[4];
    hero_actions[0]=Step;
    hero_actions[1]=Fireball;
    hero_actions[2]=Leap;
    hero_actions[3]=Wizard;
    sf::Texture hero_texture;
    hero H(B.center, hero_texture, hero_actions, 1);
    H.make_action(0, 0);
    EXPECT_EQ(H.cur_mana, 90);
}


