// Fill out your copyright notice in the Description page of Project Settings.


#include "Turtle.h"

// Sets default values
ATurtle::ATurtle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	RootComponent = boxComp;

	headBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("HeadBoxCollider"));
	headBoxComp->SetupAttachment(boxComp);

	bodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	bodyMesh->SetupAttachment(boxComp);
	
	shellMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShellMesh"));
	shellMesh->SetupAttachment(bodyMesh);

	bodyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	shellMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	projectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));

	bodyMesh->SetSimulatePhysics(true);
}

// Called when the game starts or when spawned
void ATurtle::BeginPlay()
{
	Super::BeginPlay();
	
	boxComp->OnComponentHit.AddDynamic(this, &ATurtle::OnHitCollisionEnter);
	headBoxComp->OnComponentBeginOverlap.AddDynamic(this, &ATurtle::OnHeadOverlapBegin);
}

// Called every frame
void ATurtle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//�׶��� üũ 
	if (GetActorLocation().Z > height)
	{
		float x = GetActorLocation().X;
		float y = GetActorLocation().Y;
		FVector ground = FVector(x, y, height);
		SetActorLocation(ground);
	}
	else if (GetActorLocation().Z < height)
	{
		SetisFloor(false);
	}

	//ȸ��
	if (bTurn==true)
	{
		bTurn = Turning(DeltaTime);
	}

	//���� 
	if (bTurn == false && mState == TurtleState::Idle)
	{
		speed = 500;
		PRINTLOG(TEXT("Move"));
		Move(DeltaTime);
	}
	else if (mState == TurtleState::Down)
	{

	}
	else if (mState == TurtleState::Heard)
	{
		//player ã��
		player = UGameplayStatics::GetActorOfClass(GetWorld(), APlayerCPP::StaticClass());

		if (player)
		{	
			//�÷��̾� ��ġ�� �̵�. ����ٴѴ�.
			SetActorLocation(player->GetActorLocation()+50*player->GetActorRightVector());
		}
	}
	else if (mState == TurtleState::Throw)
	{
		if (player)
		{
			frontV = player->GetActorRightVector();

			dir = frontV;
			speed = throwSpeed;
			
			//�߷� ����Ǿ����

			Move(DeltaTime);
		}
	}
	else if (mState == TurtleState::Kick)
	{
		speed = 1000;

		Move(DeltaTime);
	}
	else if (mState == TurtleState::Dead)
	{
		//player���� �浹 ����. ������ �浹 ����
	}
}

void ATurtle::SetisFloor(bool value)
{
	isFloor = value;
	if (value)
	{
		bodyMesh->SetSimulatePhysics(false);
		height = GetActorLocation().Z;
	}
	else
	{
		bodyMesh->SetSimulatePhysics(true);
	}
}

void ATurtle::OnHitCollisionEnter(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	auto backzone = Cast<AEnemyBackZone>(OtherActor);
	if (backzone)
	{
		//PRINTLOG(TEXT("HIT"));
		dir = -1 * dir; 
		bTurn = true;
		speed = 0;
		//Turn();
		oldRotate = GetActorRotation();
	}

	if (OtherActor->GetName().Contains("WallBasic"))
	{
		PRINTLOG(TEXT("Hit WallBAsicbodyMesh"));
		height = GetActorLocation().Z;
		SetisFloor(true);
		//bodyMesh->SetSimulatePhysics(false);
	}
}

//�ٴ� Hit End �� �ٽ� SimelatePhisics true��

void ATurtle::OnHeadOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//PRINTLOG(TEXT("Overlap"));
	APlayerCPP* pl = Cast<APlayerCPP>(OtherActor);
	if (pl)
	{
		//PRINTLOG(TEXT("DEAD"));
		//Destroy();
		SetState(TurtleState::Down);
	}
}

void ATurtle::Move(float DeltaTime)
{
	FVector vel = dir * speed;

	FVector P0 = GetActorLocation();
	FVector P = P0 + vel * DeltaTime;

	SetActorLocation(P, true);
}

void ATurtle::Turn()
{
	FRotator R0 = GetActorRotation();
	FRotator r = FRotator(0, 180, 0);
	SetActorRotation(R0 + r);
}

bool ATurtle::Turning(float DeltaTime)
{
	float yaw = oldRotate.Euler().Z - GetActorRotation().Euler().Z;
	//PRINTLOG(TEXT("old : %d, new : %d"), oldRotate.Euler().Z, GetActorRotation().Euler().Z);
	//PRINTLOG(TEXT("Yaw : %d"),yaw);

	if (yaw < 180.f && yaw >= 0)
	{
		PRINTLOG(TEXT("Turning, %d"),bTurn);
		FRotator R0 = GetActorRotation();
		FRotator r = FRotator(0, turnVelo, 0);
		FRotator R = R0 + r * DeltaTime;
		SetActorRotation(R);
		return true;
	}

	//���밪 ��� ->
	//turnVelo *= -1;
	oldRotate = GetActorRotation();
	return false;
}

