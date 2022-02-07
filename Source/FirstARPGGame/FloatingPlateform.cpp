// Zuocheng Wang


#include "FloatingPlateform.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"

// Sets default values
AFloatingPlateform::AFloatingPlateform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	StartPoint = FVector(0.f);
	EndPoint = FVector(0.f);

	InterpSpeed = 4.0f;
	InterpTime = 1.f;

	bInterping = false;

}

// Called when the game starts or when spawned
void AFloatingPlateform::BeginPlay()
{
	Super::BeginPlay();

	StartPoint = GetActorLocation();
	EndPoint += StartPoint;

	bInterping = false;
	GetWorldTimerManager().SetTimer(InterpTimer, this, &AFloatingPlateform::ToggleInterping, InterpTime);
	
	Distance = (EndPoint - StartPoint).Size();
}

// Called every frame
void AFloatingPlateform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (bInterping)
	{
		FVector CurrentLocation = GetActorLocation();
		FVector Interp = FMath::VInterpTo(CurrentLocation, EndPoint, DeltaTime, InterpSpeed);
		SetActorLocation(Interp);

		float DistanceTraveled = (GetActorLocation() - StartPoint).Size();

		if (Distance - DistanceTraveled <= 0.1f)
		{
			ToggleInterping();
			GetWorldTimerManager().SetTimer(InterpTimer, this, &AFloatingPlateform::ToggleInterping, InterpTime);
			
			//Swap StartPoint and EndPoint to let the platform go back and forth
			SwapVectors(StartPoint, EndPoint);
		}
	}

}

void AFloatingPlateform::ToggleInterping()
{
	bInterping = !bInterping;
}

void AFloatingPlateform::SwapVectors(FVector& VecOne, FVector& VecTwo)
{
	FVector Temp = VecOne;
	VecOne = VecTwo;
	VecTwo = Temp;
}

