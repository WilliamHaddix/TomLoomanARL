#pragma once

#include "ExplosiveBarrel.generated.h"

class UStaticMeshComponent;
class UParticleSystemComponent;
class URadialForceComponent;

DECLARE_LOG_CATEGORY_EXTERN(LogBarrel, Log, All);

UCLASS()
class AExplosiveBarrel : public AActor {
  
  GENERATED_BODY()

  UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"))
  TObjectPtr<UStaticMeshComponent> StaticMeshComp;

  UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"))
  TObjectPtr<UParticleSystemComponent> ParticleComp;

  UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"))
  TObjectPtr<URadialForceComponent> RadialForce;
  
public:
  AExplosiveBarrel();
  void Explode();
  virtual void BeginPlay() override;

  UFUNCTION()
  void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
