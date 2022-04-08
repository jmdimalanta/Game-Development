// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine (TEXT("Hey! Welcome to the Bull Cow game!"));
    PrintLine (TEXT("Guess the 3 letter Hidden word!")); //Remove number!
    PrintLine (TEXT("Press enter to continue..."));
    HiddenWord = TEXT("pie");
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    // PrintLine(Input);

    if (Input == HiddenWord)
    {
        PrintLine (TEXT("You are correct! Congrats you WON!!!"));
    }
    else
    {
        PrintLine (TEXT("Awww, you got it wrong, sorry :("));
    }
}