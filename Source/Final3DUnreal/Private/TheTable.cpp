// Fill out your copyright notice in the Description page of Project Settings.


#include "TheTable.h"

ATheTable::ATheTable()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATheTable::BeginPlay()
{
	Super::BeginPlay();
}

void ATheTable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATheTable::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}