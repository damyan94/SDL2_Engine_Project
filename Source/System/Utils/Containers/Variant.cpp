#include "stdafx.h"

#include "System/Utils/Containers/Variant.h"

bool Variant::GetBool() const
{
	AssertReturnIf(m_Type != EVariantType::Bool, bool());
	return m_Value.Bool;
}

int64_t Variant::GetInt64() const
{
	AssertReturnIf(m_Type != EVariantType::Int, int64_t());
	return m_Value.Int;
}

uint64_t Variant::GetUInt64() const
{
	AssertReturnIf(m_Type != EVariantType::UInt, uint64_t());
	return m_Value.UInt;
}

double Variant::GetDouble() const
{
	AssertReturnIf(m_Type != EVariantType::Double, double());
	return m_Value.Double;
}

const std::string& Variant::GetString() const
{
	AssertReturnIf(m_Type != EVariantType::String, std::string());
	return m_Value.String;
}

bool Variant::GetAsBool() const
{
	return *reinterpret_cast<const bool*>(&m_Value.Bool); 
}

int64_t Variant::GetAsInt() const
{
	return *reinterpret_cast<const int64_t*>(&m_Value.Int); 
}

uint64_t Variant::GetAsUInt() const
{
	return *reinterpret_cast<const uint64_t*>(&m_Value.UInt); 
}

double Variant::GetAsDouble() const
{
	return *reinterpret_cast<const double*>(&m_Value.Double); 
}

const std::string& Variant::GetAsString() const
{
	return *reinterpret_cast<const std::string*>(&m_Value.String);
}

void Variant::Test()
{
	Variant a;

	a.Set(108);
	auto b = a.Get<int32_t>();

	a.Set<std::string>("hello");
	auto c = a.GetString();

	auto d = a.GetAs<int16_t>();
}