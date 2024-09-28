// Copyright by Me


#include "AbilitySystem/AuraAbilitySystemComponent.h"

void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
    if (this)
    {
        OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);
    }
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent *AbilitySystemComponent, const FGameplayEffectSpec &EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
    FGameplayTagContainer TagContainer;
    EffectSpec.GetAllAssetTags(TagContainer);

    EffectAssetTag.Broadcast(TagContainer);
}
