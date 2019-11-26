#include "public/MyPlayer.h"
#include "UObject/ConstructorHelpers.h"
AMyPlayer::AMyPlayer()
{
	PrimaryActorTick.bCanEverTick = true;//能随计时器每帧调用
	USphereComponent*SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));//创建一个子对象，包含USphereComponent组件，命名为RootComponent，用来做碰撞器
	RootComponent = SphereComponent;//将SphereComponent设置为根组件
	SphereComponent->InitSphereRadius(40);//设置球的半径
	SphereComponent->SetCollisionProfileName(TEXT("Pawn"));//??

	UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));//创建一个Mesh组件
	SphereVisual->AttachTo(RootComponent);//将Mesh添加到Root

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("Ball'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (SphereVisualAsset.Succeeded()) {
		SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
	}
	SphereVisual->SetWorldScale3D(FVector(0.3, 0.3, 0.3));
	SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -20));
	SphereComponent->SetSphereRadius(16);
}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

