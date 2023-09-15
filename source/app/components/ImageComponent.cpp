#include "stdafx.h"

#include "app/components/ImageComponent.h"

#include "app/AppHelpers.h"

// =============================================================================
const String ImageComponent::m_Name("ImageComponent");

// =============================================================================
ImageComponent::ImageComponent()
{
}

// =============================================================================
ImageComponent::~ImageComponent()
{
}

// =============================================================================
const String& ImageComponent::GetName() const
{
	return m_Name;
}

// =============================================================================
void ImageComponent::Update(int32_t dt)
{
}