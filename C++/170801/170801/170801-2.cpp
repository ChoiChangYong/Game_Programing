#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main() {
	char* Letitgo1 = "The snow glows white on the mountain tonight \
		Not a footprint to be seen\
		A kingdom of isolation and it looks like I'm the queen \
		The wind is howling like this swirling storm inside\
		Couldn't keep it in, heaven knows I've tried\
		Don't let them in, don't let them see\
		Be the good girl you always have to be\
		Conceal, don't feel, don't let them know\
		Well, now they know\
\
		Let it go, let it go\
		Can't hold it back anymore \
		Let it go, let it go\
		Turn away and slam the door\
		I don't care what they're going to say\
		Let the storm rage on\
		The cold never bothered me anyway\
\
		It's funny how some distance \
		makes everything seem small\
		And the fears that once controlled me\
		can't get to me at all \
		It's time to see what I can do \
		To test the limits and break through\
		No right, no wrong, no rules for me\
		I'm free \
\
		Let it go, let it go\
		I am one with the wind and sky\
		Let it go, let it go\
		You'll never see me cry \
		Here I stand and here I stay\
		Let the storm rage on\
\
		My power flurries through the air into the ground\
		My soul is spiraling in frozen fractals all around\
		And one thought crystalizes like an icy blast\
		I'm never going back \
		The past is in the past\
\
		Let it go, let it go\
		And I'll rise like the break of dawn \
		Let it go, let it go\
		That perfect girl is gone\
		Here I stand in light of day\
		Let the storm rage on\
		The cold never bothered me anyway";
	char* Letitgo2 = "The snow glows white on the mountain tonight \
		Not a footprint to be seen\
		A kingdom of isolation and it looks like I'm the queen \
		The wind is howling like this swirling storm inside\
		Couldn't keep it in, heaven knows I've tried\
		Don't let them in, don't let them see\
		Be the good girl you always have to be\
		Conceal, don't feel, don't let them know\
		Well, now they know\
\
		Let it go, let it go\
		Can't hold it back anymore \
		Let it go, let it go\
		Turn away and slam the door\
		I don't care what they're going to say\
		Let the storm rage on\
		The cold never bothered me anyway\
\
		It's funny how some distance \
		makes everything seem small\
		And the fears that once controlled me\
		can't get to me at all \
		It's time to see what I can do \
		To test the limits and break through\
		No right, no wrong, no rules for me\
		I'm free \
\
		Let it go, let it go\
		I am one with the wind and sky\
		Let it go, let it go\
		You'll never see me cry \
		Here I stand and here I stay\
		Let the storm rage on\
\
		My power flurries through the air into the ground\
		My soul is spiraling in frozen fractals all around\
		And one thought crystalizes like an icy blast\
		I'm never going back \
		The past is in the past\
\
		Let it go, let it go\
		And I'll rise like the break of dawn \
		Let it go, let it go\
		That perfect girl is gone\
		Here I stand in light of day\
		Let the storm rage on\
		The cold never bothered me anyway";
	int num = 0;
	char* str1 = "Let it go";
	char* str2 = "let it go";

	while (1) {
		Letitgo1 = strstr(Letitgo1, str1);
		if (Letitgo1 == NULL) break;
		Letitgo1++;

		num++;
	}
	while (1) {
		Letitgo2 = strstr(Letitgo2, str2);
		if (Letitgo2 == NULL) break;
		Letitgo2++;

		num++;
	}
	cout << "num = " << num << endl;
	return 0;
}