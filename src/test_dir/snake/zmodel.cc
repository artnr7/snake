#include <gtest/gtest.h>
#include <unistd.h>

#include "../../brick_game/snake/model/model.hpp"
#include "utils.hpp"

// название этого теста начинается с z, чтобы он в процессе компиляции
// использовался последним и синглтон модели пропадал только здесь

TEST(get_model, get_model_1) {
  s21::Model *model_1 = s21::Model::GetModel();

  s21::Model *model_2 = s21::Model::GetModel();
  EXPECT_EQ(model_1, model_2);

  GameInfo_t g_info = model_1->GetSInfo();

  EXPECT_EQ(g_info.pause, GameState::Launched);
}

TEST(get_s_info, get_s_info_1) {
  s21::Model *model = s21::Model::GetModel();
  GameInfo_t g_info_1 = model->GetSInfo();
  GameInfo_t g_info_2 = model->GetSInfo();

  EXPECT_EQ(EQGInfo(g_info_1, g_info_2), true);
}

TEST(init_game, init_game_1) {
  s21::Model *model = s21::Model::GetModel();
  model->InitGame();
  model->GameStep();

  GameInfo_t g_info = model->GetSInfo();

  int snake_px_qty = AreObjsInField(PxCode::Snake, g_info.field);
  int apple_px_qty = AreObjsInField(PxCode::Apple, g_info.field);

  EXPECT_EQ(snake_px_qty, 4);
  EXPECT_EQ(apple_px_qty, 1);
  EXPECT_NE(g_info.field, nullptr);
  EXPECT_EQ(g_info.pause, GameState::Launched);
}

TEST(take_break, take_a_break_1) {
  s21::Model *model = s21::Model::GetModel();
  model->InitGame();
  model->TakeBreak();

  GameInfo_t g_info = model->GetSInfo();
  EXPECT_EQ(g_info.pause, GameState::Paused);
}

TEST(game_step, game_step_1) {
  s21::Model *model = s21::Model::GetModel();
  model->InitGame();
  UserAction_t action = UserAction_t::Up;

  for (int i = 0; i < 9; ++i) {
    if (i == 0) {
      action = UserAction_t::Right;
      model->SetSnakeDir(action);
    }
    if (i == 1) {
      action = UserAction_t::Down;
      model->SetSnakeDir(action);
    }
    if (i == 2) {
      action = UserAction_t::Left;
      model->SetSnakeDir(action);
    }
    if (i == 7) {
      action = UserAction_t::Up;
      model->SetSnakeDir(action);
    }

    usleep(300000);
    model->GameStep();
  }
  GameInfo_t g_info = model->GetSInfo();
  EXPECT_EQ(g_info.pause, GameState::Launched);
}

TEST(set_snake_dir_up, up_1) {
  s21::Model *model = s21::Model::GetModel();
  model->InitGame();

  UserAction_t action = UserAction_t::Up;
  model->SetSnakeDir(action);

  GameInfo_t g_info = model->GetSInfo();
  EXPECT_EQ(g_info.pause, GameState::Launched);
}

TEST(set_snake_dir_right, right_1) {
  s21::Model *model = s21::Model::GetModel();
  model->InitGame();

  UserAction_t action = UserAction_t::Right;
  model->SetSnakeDir(action);

  GameInfo_t g_info = model->GetSInfo();
  EXPECT_EQ(g_info.pause, GameState::Launched);
}

TEST(set_snake_dir_down, down_1) {
  s21::Model *model = s21::Model::GetModel();
  model->InitGame();

  UserAction_t action = UserAction_t::Down;
  model->SetSnakeDir(action);

  GameInfo_t g_info = model->GetSInfo();
  EXPECT_EQ(g_info.pause, GameState::Launched);
}

TEST(set_snake_dir_left, left_1) {
  s21::Model *model = s21::Model::GetModel();
  model->InitGame();

  UserAction_t action = UserAction_t::Left;
  model->SetSnakeDir(action);

  GameInfo_t g_info = model->GetSInfo();
  EXPECT_EQ(g_info.pause, GameState::Launched);
}

TEST(change_speed, change_speed_1) {
  s21::Model *model = s21::Model::GetModel();
  model->InitGame();

  bool hold = false;
  model->ChangeSpeed(hold);

  GameInfo_t g_info = model->GetSInfo();
  EXPECT_EQ(g_info.speed, 300);
}

TEST(change_speed, change_speed_2) {
  s21::Model *model = s21::Model::GetModel();
  model->InitGame();

  bool hold = true;
  model->ChangeSpeed(hold);

  GameInfo_t g_info = model->GetSInfo();
  EXPECT_EQ(g_info.speed, 75);
}

// оставлять последней - это синглтон
TEST(go_end, go_end_1) {
  s21::Model *model = s21::Model::GetModel();
  model->InitGame();
  model->GoEnd();

  GameInfo_t g_info = model->GetSInfo();
  EXPECT_EQ(g_info.pause, GameState::Terminated);
}
