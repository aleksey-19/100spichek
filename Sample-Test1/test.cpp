#include "pch.h"
#include "..\100spichek\game.h"

TEST(gameTest, funFonGameLoadingTrue)
{
	EXPECT_TRUE(funFonGame());
}

TEST(gameTest, funKychaSpichekLoadingTrue)
{
	EXPECT_TRUE(funKychaSpichek());
}

TEST(gameTest, funSpichkaLoadingTrue)
{
	EXPECT_TRUE(funSpichka());
}

TEST(gameTest, funKnopkiLoadingTrue)
{
	EXPECT_TRUE(funKnopki());
}

TEST(gameTest, funFonPlayersLoadingTrue)
{
	EXPECT_TRUE(funFonPlayers());
}

TEST(gameTest, funSpTwoPlayerLoadingTrue)
{
	EXPECT_TRUE(funSpTwoPlayer());
}

TEST(gameTest, funSpOnePlayerLoadingTrue)
{
	EXPECT_TRUE(funSpOnePlayer());

}

TEST(gameTest, funFontLoadingTrue)
{
	EXPECT_TRUE(funFont());
}

TEST(gameTest, funSchetchikLoadingTrue)
{
	EXPECT_TRUE(funSchetchik());
}

TEST(gameTest, intSchet)
{
	
}