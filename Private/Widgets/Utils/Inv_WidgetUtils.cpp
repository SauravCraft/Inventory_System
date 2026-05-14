// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Utils/Inv_WidgetUtils.h"

int32 UInv_WidgetUtils::GetGridPositionByIndex(const FIntPoint& GridSize, int32 Column)
{
	return GridSize.X + GridSize.Y * Column;
}
