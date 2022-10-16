#include <iostream>
#include <vector>
#include <array>
#include <sstream>
#include <algorithm>
#include <random>
#include <chrono>

// �ϳ��� ī�� ����ü
struct card {
	int number;		// ī���� ��ȣ

	enum suit {		// ī���� ���
		HEART,
		SPADE,
		CLUB,
		DIAMOND
	} suit;

	
	std::string to_string() const {
		std::ostringstream os;		// ostringstream: ���ڿ� format�� �����Ͽ� ������ �� ���

		if (number > 0 && number <= 10)		// �ǹ� : �� 1��������
			os << number;
		else {								// 1, 11, 12, 13 �Է� �� ó��
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
	std::array<card, 52> deck;		// ī�� 52���� �̷���� �� ����
	std::vector<card> player1, player2, player3, player4;		// �� �÷��̾��� �� ����

	// ���� ����
	// 1���� 13���� ���ڸ� ���� �Բ� deck�� ����
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

	// ī�带 �� �÷��̾�� �����ִ� �Լ�
	void dealCards() {
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();	// shuffle�� ���� seed �Ҵ�
		std::shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));	// ī�带 ����
		player1 = { deck.begin(), deck.begin() + 13 };			// �� �÷��̾� �� 13���� ī��
		player2 = { deck.begin() + 13, deck.begin() + 26 };
		player3 = { deck.begin() + 26, deck.begin() + 39 };
		player4 = { deck.begin() + 39, deck.end() };
	}

	// ī�带 ���ϰ� ����� �Լ�
	bool compareAndRemove(std::vector<card>& p1, std::vector<card>& p2) {
		
		// �� player�� ���� ������ ī���� ���ڸ� ��
		// ���� ���ڰ� ���� ��� �� player�� ī�带 ��� ����
		if (p1.back().number == p2.back().number) {
			p1.pop_back();
			p2.pop_back();
			return true;
		}

		// �� player�� ���ڰ� ���� ���� ���
		return false;
	}

	// �� �÷��̾��� ī�带 �� �� ������ �� �÷��̾��� ī�� ��
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

		// ���� �õ带 �Ҵ� �޾� �÷��̾��� ī�带 �ٽ� ����
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::shuffle(player1.begin(), player1.end(), std::default_random_engine(seed));
		std::shuffle(player2.begin(), player2.end(), std::default_random_engine(seed));
		std::shuffle(player3.begin(), player3.end(), std::default_random_engine(seed));
		std::shuffle(player4.begin(), player4.end(), std::default_random_engine(seed));
	}

	// ������ ����Ǵ� ���
	// ��ü �÷��̾� �� �ϳ��� �÷��̾�� ī�尡 �������� ���
	bool isGameComplete() const {
		return player1.empty() || player2.empty() || player3.empty() || player4.empty();
	}

	// ���� ���� ����
	// ��ü �÷��̾��� ī�尡 �����ִ� ���
	void playGame() {
		while (not isGameComplete()) {
			playOneRound();
		}
	}

	// �� �÷��̾��� ī�� ���� �� ��� �ش� �÷��̾� ����(�����)
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
	std::cout << winner << "�� �÷��̾ �̰���ϴ�!" << std::endl;

	return 0;

}