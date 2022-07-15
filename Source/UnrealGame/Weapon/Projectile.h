// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class UNREALGAME_API AProjectile : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Component", DisplayName="子弹碰撞盒子组件")
	class UBoxComponent* CollisionBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Component", DisplayName="子弹网格体组件")
	class UStaticMeshComponent* ProjectileMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Component", DisplayName="子弹运动组件")
	class UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Particle System", DisplayName="子弹追踪轨迹粒子效果")
	class UParticleSystem* Tracer;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Particle System", DisplayName="子弹追踪轨迹粒子系统组件")
	class UParticleSystemComponent* TracerComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Particle System", DisplayName="子弹击中粒子效果")
	UParticleSystem* ImpactParticles;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Particle System", DisplayName="子弹击中声音效果")
	class USoundCue* ImpactSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="伤害值")
	float Damage=20.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Projectile Mesh", DisplayName="伤害值")
	FTransform DeltaTransform;
	
public:	
	// Sets default values for this actor's properties
	AProjectile();
	
	virtual void Destroyed() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnHit(UPrimitiveComponent* HitComponent
		, AActor* OtherActor
		, UPrimitiveComponent* OtherComponent
		, FVector NormalImpulse
		, const FHitResult& HitResult);

};
