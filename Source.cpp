#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;

class Player
{
private:
	std::vector<int> dices;
public:
	Player() {}
	Player(int num)
	{
		for (int i = 0; i < num; i++)
		{
			dices.push_back(rand() % 6 + 1);
		}
	}

	void generateNew()
	{
		for (auto i : dices)
		{
			i = rand() % 6 + 1;
		}
	}

	int getSum()
	{
		int sum = 0;
		for (auto i : dices)
		{
			sum += i;
		}
		return sum;
	}
};

class Players
{
	std::vector<Player> players;
public:
	Players(int diceNum, int playerNum)
	{
		for (int i = 0; i < playerNum; i++)
		{
			players.push_back(Player(diceNum));
		}
	}
	int getMax()
	{
		int sum = 0;
		for (auto i : players)
		{
			if (sum < i.getSum()) sum = i.getSum();
		}
		return sum;
	}
	int getSize()
	{
		return players.size();
	}

	std::vector<int> getWinners()
	{
		std::vector<int> winnerNums;
		for (int i = 0; i < players.size(); i++)
		{
			if (players[i].getSum() == this->getMax())
			{
				winnerNums.push_back(i);
			}
		}
		return winnerNums;
	}

	Player operator[](int index)
	{
		return players[index];
	}
};

int main()
{
	cout << "enter number of dice:\n";
	int diceNum;
	std::cin >> diceNum;
	cout << "enter number of players:\n";
	int playersNum;
	std::cin >> playersNum;

	bool retry;
	do
	{
		system("cls");
		srand(time(0));
		Players players(diceNum, playersNum);
		for (int i = 0; i < players.getSize(); i++)
		{
			cout << "Player #" << i << " = " << players[i].getSum() << "\n";
		}

		cout << "Winners:";
		for (auto i : players.getWinners())
		{
			cout << "#" << i << " ";
		}
		cout << "\nreroll?\n";
		std::cin >> retry;
	} while (retry);
}