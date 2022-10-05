#include <iostream>
#include <vector>
#include <array>
#include <sstream>
#include <algorithm>
#include <random>
#include <chrono>

// 하나의 카드 구조체
struct card {
	int number;		// 카드의 번호

	enum suit {		// 카드의 모양
		HEART,
		SPADE,
		CLUB,
		DIAMOND
	} suit;

	
	std::string to_string() const {
		std::ostringstream os;		// ostringstream: 문자열 format을 조합하여 저장할 때 사용

		if (number > 0 && number <= 10)		// 의문 : 왜 1까지이지
			os << number;
		else {								// 1, 11, 12, 13 입력 시 처리
			switch (number) {
			case 1:
				os << "Ace";
				break;
			case 11:
				os << "Jack";
				break;
			case 12:
				os << "Queen";
				break;
			case 13:
				os << "King";
				break;
			default:
				return "Invalid card";
			}
		}

		os << " of ";

		switch (suit) {
			case HEART:
				os << "hearts";
				break;
			case SPADE:
				os << "spades";
				break;
			case CLUB:
				os << "clubs";
				break;
			case DIAMOND:
				os << "diamonds";
				break;
		}

		return os.str();
	}
};

struct game {
	std::array<card, 52> deck;		// 카드 52개로 이루어진 덱 생성
	std::vector<card> player1, player2, player3, player4;		// 각 플레이어의 덱 선언

	// 덱을 생성
	// 1부터 13까지 숫자를 모양과 함께 deck에 생성
	void buildDeck() {
		for (int i = 0; i < 13; i++)
			deck[i] = card{ i + 1, card::HEART };
		for (int i = 0; i < 13; i++)
			deck[i + 13] = card{ i + 1, card::SPADE };
		for (int i = 0; i < 13; i++)
			deck[i + 26] = card{ i + 1, card::CLUB };
		for (int i = 0; i < 13; i++)
			deck[i + 39] = card{ i + 1, card::DIAMOND };
	}

	// 카드를 각 플레이어에게 나눠주는 함수
	void dealCards() {
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();	// shuffle을 위한 seed 할당
		std::shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));	// 카드를 셔플
		player1 = { deck.begin(), deck.begin() + 13 };			// 각 플레이어 당 13개의 카드
		player2 = { deck.begin() + 13, deck.begin() + 26 };
		player3 = { deck.begin() + 26, deck.begin() + 39 };
		player4 = { deck.begin() + 39, deck.end() };
	}

	// 카드를 비교하고 지우는 함수
	bool compareAndRemove(std::vector<card>& p1, std::vector<card>& p2) {
		
		// 두 player의 가장 마지막 카드의 숫자를 비교
		// 만약 숫자가 같은 경우 두 player의 카드를 모두 제거
		if (p1.back().number == p2.back().number) {
			p1.pop_back();
			p2.pop_back();
			return true;
		}

		// 두 player의 숫자가 같지 않은 경우
		return false;
	}

	// 두 플레이어의 카드를 비교 후 나머지 두 플레이어의 카드 비교
	void playOneRound() {
		if (compareAndRemove(player1, player2)) {
			compareAndRemove(player3, player4);
			return;
		}
		else if (compareAndRemove(player1, player3)) {
			compareAndRemove(player2, player4);
			return;
		}
		else if (compareAndRemove(player1, player4)) {
			compareAndRemove(player2, player3);
			return;
		}
		else if (compareAndRemove(player2, player3)) {
			return;
		}
		else if (compareAndRemove(player2, player4)) {
			return;
		}
		else if (compareAndRemove(player3, player4)) {
			return;
		}

		// 랜덤 시드를 할당 받아 플레이어의 카드를 다시 섞음
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::shuffle(player1.begin(), player1.end(), std::default_random_engine(seed));
		std::shuffle(player2.begin(), player2.end(), std::default_random_engine(seed));
		std::shuffle(player3.begin(), player3.end(), std::default_random_engine(seed));
		std::shuffle(player4.begin(), player4.end(), std::default_random_engine(seed));
	}

	// 게임이 종료되는 경우
	// 전체 플레이어 중 하나의 플레이어라도 카드가 없어졌을 경우
	bool isGameComplete() const {
		return player1.empty() || player2.empty() || player3.empty() || player4.empty();
	}

	// 게임 진행 조건
	// 전체 플레이어의 카드가 남아있는 경우
	void playGame() {
		while (not isGameComplete()) {
			playOneRound();
		}
	}

	// 한 플레이어의 카드 덱이 빈 경우 해당 플레이어 리턴(우승자)
	int getWinner() const {
		if (player1.empty())
			return 1;
		if (player2.empty())
			return 2;
		if (player3.empty())
			return 3;
		if (player4.empty())
			return 4;
	}
};

int main() {

	game newGame;
	newGame.buildDeck();
	newGame.dealCards();
	newGame.playGame();
	auto winner = newGame.getWinner();
	std::cout << winner << "번 플레이어가 이겼습니다!" << std::endl;

	return 0;

}