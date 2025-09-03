// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Math.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{

	Super::BeginPlay();
	Event_Count = 0;
	Total_Distance = 0;
	VectorArray.Add(FVector2D(0,0));
	FVector2D& Vec = VectorArray[0];
	UE_LOG(LogTemp, Warning, TEXT("X = %f, Y = %f"), Vec.X, Vec.Y);
	for (int i = 0; i < 10; i++) {
		move();
	}
	UE_LOG(LogTemp, Warning, TEXT("Total distance: %f"), Total_Distance);
	UE_LOG(LogTemp, Warning, TEXT("Triggerd Event Num: %d"), Event_Count);
	
	
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::move()
{
	FVector2D Vec = VectorArray[VectorArray.Num() - 1];	
	VectorArray.Add(FVector2D(Vec.X+ step(),Vec.Y + step()));
	FVector2D Vec2 = VectorArray[VectorArray.Num() - 1];
	UE_LOG(LogTemp, Warning, TEXT("X = %f, Y = %f"), Vec2.X, Vec2.Y);
	float x_distance = Vec2.X - Vec.X;
	float y_distance = Vec2.Y - Vec.Y;
	float distance = FMath::Sqrt(x_distance * x_distance + y_distance * y_distance);
	UE_LOG(LogTemp, Warning, TEXT("distance: %f"), distance);
	Total_Distance += distance;
	
	
	if (is_event()) {
		UE_LOG(LogTemp, Log, TEXT("Event Triggered!"));
		Event_Count++;
	}
	
}

int32_t AMyActor::step()
{
	int32_t r_step = 0;
	r_step = FMath::RandRange(-1, 1);
	return r_step;
}

bool AMyActor::is_event()
{
	int32 RandomValue = FMath::RandRange(1, 100); // 1 ~ 100의 난수 생성
	if (RandomValue <= 50)
	{
		return true;
	}
	else
	{
		return false;
	}
}

