#include "../../brick_game/snake/controller/controller.hpp"
#include "utils.hpp"
#include <gtest/gtest.h>
#include <iostream>

TEST(userInput_start, right_1) {
  s21::Controller::userInput(UserAction_t::Start, false);
  GameInfo_t g_info = s21::Controller::updateCurrentState();

  GameInfo_t test_g_info = {};
  GInfoInit(test_g_info);
  test_g_info.pause = GameState::Launched;

  EXPECT_EQ(EQGInfo(g_info, test_g_info), true);
}

TEST(userInput_start, wrong_1) {
  s21::Controller::userInput(UserAction_t::Start, false);
  GameInfo_t g_info = s21::Controller::updateCurrentState();

  GameInfo_t test_g_info = {};
  GInfoWrongInit(test_g_info);

  EXPECT_EQ(EQGInfo(g_info, test_g_info), false);
}

TEST(userInput_pause, pause_1) {
  s21::Controller::userInput(UserAction_t::Start, false);
  s21::Controller::userInput(UserAction_t::Pause, false);

  GameInfo_t g_info = s21::Controller::updateCurrentState();
  GameInfo_t test_g_info = {};
  GInfoInit(test_g_info);
  test_g_info.pause = GameState::Paused;

  EXPECT_EQ(g_info.pause, test_g_info.pause);
}

TEST(userInput_up, up_1) {
  s21::Controller::userInput(UserAction_t::Start, false);
  s21::Controller::userInput(UserAction_t::Up, false);

  GameInfo_t g_info = s21::Controller::updateCurrentState();

  EXPECT_EQ(g_info.pause, GameState::Launched);
}

TEST(userInput_right, right_1) {
  s21::Controller::userInput(UserAction_t::Start, false);
  s21::Controller::userInput(UserAction_t::Up, false);

  GameInfo_t g_info = s21::Controller::updateCurrentState();

  EXPECT_EQ(g_info.pause, GameState::Launched);
}

TEST(userInput_down, down_1) {
  s21::Controller::userInput(UserAction_t::Start, false);
  s21::Controller::userInput(UserAction_t::Up, false);

  GameInfo_t g_info = s21::Controller::updateCurrentState();

  EXPECT_EQ(g_info.pause, GameState::Launched);
}

TEST(userInput_left, left_1) {
  s21::Controller::userInput(UserAction_t::Start, false);
  s21::Controller::userInput(UserAction_t::Up, false);

  GameInfo_t g_info = s21::Controller::updateCurrentState();

  EXPECT_EQ(g_info.pause, GameState::Launched);
}

TEST(updateCurrentState, get_1) {
  GameInfo_t g_info_1 = s21::Controller::updateCurrentState();
  GameInfo_t g_info_2 = s21::Controller::updateCurrentState();

  EXPECT_EQ(EQGInfo(g_info_1, g_info_2), true);
}

TEST(userInput_terminate, terminate_1) {
  s21::Controller::userInput(UserAction_t::Start, false);
  s21::Controller::userInput(UserAction_t::Terminate, false);

  GameInfo_t g_info = s21::Controller::updateCurrentState();

  EXPECT_EQ(g_info.pause, GameState::Terminated);
}
