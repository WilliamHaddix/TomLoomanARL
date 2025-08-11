#pragma once
#include "Components/SphereComponent.h"
#include "MagicProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UParticleSystemComponent;

UCLASS()
class AMagicProjectile : public AActor{

  GENERATED_BODY()

  UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"))
  TObjectPtr<USphereComponent> CollisionComp;
  
  UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"))
  TObjectPtr<UProjectileMovementComponent> MovementComp;
  
  UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"))
  TObjectPtr<UParticleSystemComponent> ParticleComp;
  
public:
  AMagicProjectile();
};
