#include "iostream"
#include "vector"
#include "Windows.h"
#include <random>
#include "ctime"
#include <fstream>
using namespace std;

bool restart_game = true;

class Game {
protected:
    string game_word;
    string temp; 
    string letter_temp;
    char letter;
    bool is_right = false;
    bool game_win = false;
    int chance_to_win = 8;
    int search_time;
    bool game_start = true;
public:
    Game() {
    }
    ~Game() {
    }
    void start() {
        
        vector<string> words;
        ifstream file("input.txt");
        while (!file.eof()) {
            
            file >> game_word;
            words.push_back(game_word);
        }
        default_random_engine gen{ random_device()() };
        uniform_int_distribution<> dist(1, words.size() - 1);
        game_word = words[dist(gen)];
        letter_temp += '&';
        
        temp.resize(game_word.size());
        for (int i = 0; i < temp.size(); i++) 
        {
            temp[i] = '_';
        }
        while (!game_win && !chance_to_win == 0) {

            for (int i = 0; game_word[i]; i++) {
                if (letter == game_word[i] || letter == game_word[i] + 32) {//�������� �� �������
                    temp[i] = game_word[i];
                    is_right = true;
                    
                }
            }
            if (game_word == temp) { //�������� �� ��� �������
                game_win = true;
                break;
            }

            system("cls");
            
            cout << "\t��������\n����� - ";
            
            for (int i = 0; i < temp.size(); i++) {
                cout << temp[i] << " ";
            }
            if (!game_start) { //�������� ������ ��� �� ��������� �� ���������� ��������� �����
                
                for (int i = 1; i <= letter_temp.size(); i++) {
                    if (letter == letter_temp[i]) { //�������� �� ���������� ����
                        
                        cout << letter << " ";
                        cout << "\n�� ��� ������� �� �i����! ����i�� ����.\n";
                        is_right = false;
                        break;
                    }
                    else {
                        if (i == letter_temp.size()) {
                            if (is_right) {
                                cout << "\n�� ������� �i����!\n";
                                letter_temp += letter;
                                letter_temp = +(letter - 32);
                                is_right = false;
                                break;
                            }
                            else {
                                cout << "\n���� �i���� ���i���\n";
                                chance_to_win--;
                                if (chance_to_win == 7) {
                                    cout << "\n  _______";
                                    cout << "\n  |/";
                                    cout << "\n  |";
                                    cout << "\n  |";
                                    cout << "\n  |";
                                    cout << "\n  |";
                                    cout << "\n  |";
                                    cout << "\n  |";
                                    cout << "\n  |";
                                    cout << "\n__|________";
                                    cout << "\n|         |";
                                }
                                if (chance_to_win == 6) {
                                    cout << "\n  _______";
                                    cout << "\n  |/";
                                    cout << "\n  |     ( )";
                                    cout << "\n  |";
                                    cout << "\n  |";
                                    cout << "\n  |";
                                    cout << "\n  |";
                                    cout << "\n  |";
                                    cout << "\n  |";
                                    cout << "\n__|________";
                                    cout << "\n|         |";
                                }
                                if (chance_to_win == 5) {
                                    cout << "\n  _______";
                                    cout << "\n  |/";
                                    cout << "\n  |     ( )";
                                    cout << "\n  |      |";
                                    cout << "\n  |";
                                    cout << "\n  |";
                                    cout << "\n  |";
                                    cout << "\n  |";
                                    cout << "\n  |";
                                    cout << "\n__|________";
                                    cout << "\n|         |";
                                }
                                if (chance_to_win == 4) {
                                    cout << "\n  _______";
                                    cout << "\n  |/";
                                    cout << "\n  |     ( )";
                                    cout << "\n  |      |_";
                                    cout << "\n  |        \\";
                                    cout << "\n  |";
                                    cout << "\n  |";
                                    cout << "\n  |";
                                    cout << "\n  |";
                                    cout << "\n__|________";
                                    cout << "\n|         |";
                                }
                                if (chance_to_win == 3) {
                                    cout << "\n  _______";
                                    cout << "\n  |/";
                                    cout << "\n  |     ( )";
                                    cout << "\n  |     _|_";
                                    cout << "\n  |    /   \\";
                                    cout << "\n  |";
                                    cout << "\n  |";
                                    cout << "\n  |";
                                    cout << "\n  |";
                                    cout << "\n__|________";
                                    cout << "\n|         |";
                                }
                                if (chance_to_win == 2) {
                                    cout << "\n  _______";
                                    cout << "\n  |/";
                                    cout << "\n  |     ( )";
                                    cout << "\n  |     _|_";
                                    cout << "\n  |    / | \\";
                                    cout << "\n  |      |";
                                    cout << "\n  |";
                                    cout << "\n  |";
                                    cout << "\n  |";
                                    cout << "\n__|________";
                                    cout << "\n|         |";
                                }
                                if (chance_to_win == 1) {
                                    cout << "\n  _______";
                                    cout << "\n  |/";
                                    cout << "\n  |     ( )";
                                    cout << "\n  |     _|_";
                                    cout << "\n  |    / | \\";
                                    cout << "\n  |      |";
                                    cout << "\n  |     / \\";
                                    cout << "\n  |    /   \\";
                                    cout << "\n  |";
                                    cout << "\n__|________";
                                    cout << "\n|         |";
                                }
                                break;
                            }
                        }
                    }
                }
                if (chance_to_win == 0) break;
            }
            
            cout << "\n�������� �i����:";
            cin >> letter;
            game_start = false;


            /*cout << "\n�i���� ��i ��� ���� :" << endl;
            vector<char> h;
            for (int i = 1; i < letter_temp.size(); i++) {

                h.push_back(letter);

                for (int i = 0; i < h.size(); i++) cout << h[i] << " ";
            }
            */
        }
        if (game_win) {
            system("cls");
            cout << "����� - ";
            for (int i = 0; i < temp.size(); i++) //������� �������� �����
            {
                cout << temp[i] << " ";
            }
            cout << "\n��������!!!\n";
            search_time = clock() / 1000;
            cout << "\n��� ����: " << search_time << " sec" << endl;
            cout << "����� ����������: " << chance_to_win << endl;
        }
        else {
            int chance = 8;
            system("cls");
            cout << "����� - ";
            for (int i = 0; i < game_word.size(); i++) {
                cout << game_word[i] << " ";
            }
            cout << "\n�������!!!\n";
            search_time = clock() / 1000;
            cout << "\n��� ����: " << search_time<< " sec" << endl;

            cout << "C���� ����: " << chance <<"\n����������: "<< chance_to_win << endl;
        }
        
        char restart;
        cout << "\n������ �i����� �� ���?(Y/N)";
        cin >> restart;
        if (restart == 'N' || restart == 'n') { restart_game = false; }

    }
   

};

void main() {
    setlocale(LC_CTYPE, "UKR");
    do {
        Game gallows;
        gallows.start();
    } while (restart_game);
  
}

