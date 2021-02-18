#include <stdio.h>
#include <iostream>

using namespace std;

struct Answer
{
    string text;
    bool isCorrect;
};

struct Question
{
    string text;
    Answer answer[3];
};

Question question[5] = {
    {"What is the rarest M&M color?", {{"brown", true}, {"yellow", false}, {"red", false}}},
    {"In a website browser address bar, what does “www” stand for?", {{"World Wide Web", true}, {"Weird Wide Web", false}, {"World Width Web", false}}},
    {"In what year were the first Air Jordan sneakers released?", {{"1984", true}, {"1977", false}, {"2015", false}}},
    {"According to Greek mythology, who was the first woman on earth?", {{"Pandora", true}, {"Gaia", false}, {"Athena", false}}},
    {"Which African country was formerly known as Abyssinia?", {{"Ethiopia", true}, {"South Africa", false}, {"Nigeria", false}}}};

void printAnswers(Answer answer[3])
{
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << ". " << answer[i].text << endl;
    }
}

void printQuestion(Question question)
{
    cout << question.text << endl;

    printAnswers(question.answer);
}

void answerChecker(bool isCorrect)
{
    if (isCorrect)
    {
        cout << "Correct!" << endl;
    }
    else
    {
        cout << "Incorrect" << endl;
    }
}

void input(Question question)
{
    printQuestion(question);

    int ans;
    cout << "Choose 1 - 3: ";
    cin >> ans;

    answerChecker(question.answer[ans - 1].isCorrect);
}

int main(void)
{
    int i = 0;

    while (i < 5)
    {
        input(question[i]);
        i++;
    }

    return 0;
}