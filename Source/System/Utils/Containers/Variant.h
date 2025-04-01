//#pragma once
//
//enum class EVariantType
//	: int8_t
//{
//	Invalid = -1,
//
//	Bool,
//	Int8,
//	Int16,
//	Int32,
//	Int64,
//	UInt8,
//	UInt16,
//	UInt32,
//	UInt64,
//	Float,
//	Double,
//	String,
//
//	Count
//};
//
//class Variant
//{
//public:
//	Variant() : m_Type(EVariantType::Invalid) {};
//	~Variant() { Destroy(); }
//
//	template <typename T>
//	void Set(const T& value)
//	{
//		Destroy();
//
//		if constexpr (std::is_same_v<T, bool>) { m_Value.Bool = value; m_Type = EVariantType::Bool; }
//		else if constexpr (std::is_same_v<T, int8_t>) { m_Value.Int8 = value; m_Type = EVariantType::Int8; }
//		else if constexpr (std::is_same_v<T, int16_t>) { m_Value.Int16 = value; m_Type = EVariantType::Int16; }
//		else if constexpr (std::is_same_v<T, int32_t>) { m_Value.Int32 = value; m_Type = EVariantType::Int32; }
//		else if constexpr (std::is_same_v<T, int64_t>) { m_Value.Int64 = value; m_Type = EVariantType::Int64; }
//		else if constexpr (std::is_same_v<T, uint8_t>) { m_Value.UInt8 = value; m_Type = EVariantType::UInt8; }
//		else if constexpr (std::is_same_v<T, uint16_t>) { m_Value.UInt16 = value; m_Type = EVariantType::UInt16; }
//		else if constexpr (std::is_same_v<T, uint32_t>) { m_Value.UInt32 = value; m_Type = EVariantType::UInt32; }
//		else if constexpr (std::is_same_v<T, uint64_t>) { m_Value.UInt64 = value; m_Type = EVariantType::UInt64; }
//		else if constexpr (std::is_same_v<T, float>) { m_Value.Float = value; m_Type = EVariantType::Float; }
//		else if constexpr (std::is_same_v<T, double>) { m_Value.Double = value; m_Type = EVariantType::Double; }
//		else if constexpr (std::is_same_v<T, std::string>)
//		{
//			new (&m_Value.String) std::string(value); // Placement new for non-trivial type
//			m_Type = EVariantType::String;
//		}
//		else
//		{
//			Assert::Assert("Unsupported type");
//		}
//	}
//
//	template <typename T>
//	const T& Get() const
//	{
//		if constexpr (std::is_same_v<T, bool>) { AssertReturnIf(m_Type != EVariantType::Bool, T());	return m_Value.Bool; }
//		else if constexpr (std::is_same_v<T, int8_t>) { AssertReturnIf(m_Type != EVariantType::Int8, T());	return m_Value.Int8; }
//		else if constexpr (std::is_same_v<T, int16_t>) { AssertReturnIf(m_Type != EVariantType::Int16, T());	return m_Value.Int16; }
//		else if constexpr (std::is_same_v<T, int32_t>) { AssertReturnIf(m_Type != EVariantType::Int32, T());	return m_Value.Int32; }
//		else if constexpr (std::is_same_v<T, int64_t>) { AssertReturnIf(m_Type != EVariantType::Int64, T());	return m_Value.Int64; }
//		else if constexpr (std::is_same_v<T, uint8_t>) { AssertReturnIf(m_Type != EVariantType::UInt8, T());	return m_Value.UInt8; }
//		else if constexpr (std::is_same_v<T, uint16_t>) { AssertReturnIf(m_Type != EVariantType::UInt16, T());	return m_Value.UInt16; }
//		else if constexpr (std::is_same_v<T, uint32_t>) { AssertReturnIf(m_Type != EVariantType::UInt32, T());	return m_Value.UInt32; }
//		else if constexpr (std::is_same_v<T, uint64_t>) { AssertReturnIf(m_Type != EVariantType::UInt64, T());	return m_Value.UInt64; }
//		else if constexpr (std::is_same_v<T, float>) { AssertReturnIf(m_Type != EVariantType::Float, T());	return m_Value.Float; }
//		else if constexpr (std::is_same_v<T, double>) { AssertReturnIf(m_Type != EVariantType::Double, T());	return m_Value.Double; }
//		else if constexpr (std::is_same_v<T, std::string>) { AssertReturnIf(m_Type != EVariantType::String, T());	return m_Value.String; }
//		else { Assert::Assert("Unsupported type"); return T(); }
//	}
//
//	template <typename T>
//	const T& GetAs() const
//	{
//		if constexpr (std::is_same_v<T, bool>) { return *reinterpret_cast<const T*>(&m_Value.Bool); }
//		else if constexpr (std::is_same_v<T, int8_t>) { return *reinterpret_cast<const T*>(&m_Value.Int8); }
//		else if constexpr (std::is_same_v<T, int16_t>) { return *reinterpret_cast<const T*>(&m_Value.Int16); }
//		else if constexpr (std::is_same_v<T, int32_t>) { return *reinterpret_cast<const T*>(&m_Value.Int32); }
//		else if constexpr (std::is_same_v<T, int64_t>) { return *reinterpret_cast<const T*>(&m_Value.Int64); }
//		else if constexpr (std::is_same_v<T, uint8_t>) { return *reinterpret_cast<const T*>(&m_Value.UInt8); }
//		else if constexpr (std::is_same_v<T, uint16_t>) { return *reinterpret_cast<const T*>(&m_Value.UInt16); }
//		else if constexpr (std::is_same_v<T, uint32_t>) { return *reinterpret_cast<const T*>(&m_Value.UInt32); }
//		else if constexpr (std::is_same_v<T, uint64_t>) { return *reinterpret_cast<const T*>(&m_Value.UInt64); }
//		else if constexpr (std::is_same_v<T, float>) { return *reinterpret_cast<const T*>(&m_Value.Float); }
//		else if constexpr (std::is_same_v<T, double>) { return *reinterpret_cast<const T*>(&m_Value.Double); }
//		else if constexpr (std::is_same_v<T, std::string>) { return *reinterpret_cast<const T*>(&m_Value.String); }
//		else { Assert::Assert("Unsupported type"); return T(); }
//	}
//
//	bool		GetBool() const { AssertReturnIf(m_Type != EVariantType::Bool, bool());				return m_Value.Bool; }
//	int8_t		GetInt8() const { AssertReturnIf(m_Type != EVariantType::Int8, int8_t());			return m_Value.Int8; }
//	int16_t		GetInt16() const { AssertReturnIf(m_Type != EVariantType::Int16, int16_t());			return m_Value.Int16; }
//	int32_t		GetInt32() const { AssertReturnIf(m_Type != EVariantType::Int32, int32_t());			return m_Value.Int32; }
//	int64_t		GetInt64() const { AssertReturnIf(m_Type != EVariantType::Int64, int64_t());			return m_Value.Int64; }
//	uint8_t		GetUInt8() const { AssertReturnIf(m_Type != EVariantType::UInt8, uint8_t());			return m_Value.UInt8; }
//	uint16_t	GetUInt16() const { AssertReturnIf(m_Type != EVariantType::UInt16, uint16_t());		return m_Value.UInt16; }
//	uint32_t	GetUInt32() const { AssertReturnIf(m_Type != EVariantType::UInt32, uint32_t());		return m_Value.UInt32; }
//	uint64_t	GetUInt64() const { AssertReturnIf(m_Type != EVariantType::UInt64, uint64_t());		return m_Value.UInt64; }
//	float		GetFloat() const { AssertReturnIf(m_Type != EVariantType::Float, float());			return m_Value.Float; }
//	double		GetDouble() const { AssertReturnIf(m_Type != EVariantType::Double, double());			return m_Value.Double; }
//	const std::string& GetString() const { AssertReturnIf(m_Type != EVariantType::String, std::string());	return m_Value.String; }
//
//	bool		GetAsBool() const { return *reinterpret_cast<const bool*>(&m_Value.Bool); }
//	int8_t		GetAsInt8() const { return *reinterpret_cast<const int8_t*>(&m_Value.Int8); }
//	int16_t		GetAsInt16() const { return *reinterpret_cast<const int16_t*>(&m_Value.Int16); }
//	int32_t		GetAsInt32() const { return *reinterpret_cast<const int32_t*>(&m_Value.Int32); }
//	int64_t		GetAsInt64() const { return *reinterpret_cast<const int64_t*>(&m_Value.Int64); }
//	uint8_t		GetAsUInt8() const { return *reinterpret_cast<const uint8_t*>(&m_Value.UInt8); }
//	uint16_t	GetAsUInt16() const { return *reinterpret_cast<const uint16_t*>(&m_Value.UInt16); }
//	uint32_t	GetAsUInt32() const { return *reinterpret_cast<const uint32_t*>(&m_Value.UInt32); }
//	uint64_t	GetAsUInt64() const { return *reinterpret_cast<const uint64_t*>(&m_Value.UInt64); }
//	float		GetAsFloat() const { return *reinterpret_cast<const float*>(&m_Value.Float); }
//	double		GetAsDouble() const { return *reinterpret_cast<const double*>(&m_Value.Double); }
//	const std::string& GetAsString() const { return *reinterpret_cast<const std::string*>(&m_Value.String); }
//
//	static void Test();
//
//private:
//	void Destroy()
//	{
//		if (m_Type == EVariantType::String)
//		{
//			m_Value.String.~basic_string();
//		}
//
//		std::memset(&m_Value, 0, sizeof(ValueUnion));
//		m_Type = EVariantType::Invalid;
//	}
//
//private:
//	union ValueUnion
//	{
//		bool		Bool;
//
//		int8_t		Int8;
//		int16_t		Int16;
//		int32_t		Int32;
//		int64_t		Int64;
//
//		uint8_t		UInt8;
//		uint16_t	UInt16;
//		uint32_t	UInt32;
//		uint64_t	UInt64;
//
//		float		Float;
//		double		Double;
//
//		std::string String;
//
//		ValueUnion() : Bool(false) {};
//		~ValueUnion() {};
//	};
//
//	ValueUnion		m_Value;
//	EVariantType	m_Type;
//};

#pragma once

enum class EVariantType
	: int8_t
{
	Invalid = -1,

	Bool,
	Int,
	UInt,
	Double,
	String,

	Count
};

class Variant
{
public:
	Variant() : m_Type(EVariantType::Invalid) {};
	~Variant() { Destroy(); }

	template <typename T>
	void Set(const T& value)
	{
		Destroy();

		if constexpr (std::is_same_v<T, bool>)				{ m_Value.Bool		= value; m_Type = EVariantType::Bool;	}
		else if constexpr (std::is_same_v<T, int64_t>)		{ m_Value.Int		= value; m_Type = EVariantType::Int;	}
		else if constexpr (std::is_same_v<T, uint64_t>)		{ m_Value.UInt		= value; m_Type = EVariantType::UInt;	}
		else if constexpr (std::is_same_v<T, double>)		{ m_Value.Double	= value; m_Type = EVariantType::Double;	}
		else if constexpr (std::is_same_v<T, std::string>)
		{
			new (&m_Value.String) std::string(value); // Placement new for non-trivial type
			m_Type = EVariantType::String;
		}
		else
		{
			Assert::Assert("Unsupported type");
		}
	}

	template <typename T>
	const T& Get() const
	{
		if constexpr (std::is_same_v<T, bool>)				{ AssertReturnIf(m_Type != EVariantType::Bool, T());	return m_Value.Bool;	}
		else if constexpr (std::is_same_v<T, int64_t>)		{ AssertReturnIf(m_Type != EVariantType::Int, T());		return m_Value.Int;	}
		else if constexpr (std::is_same_v<T, uint64_t>)		{ AssertReturnIf(m_Type != EVariantType::UInt, T());	return m_Value.UInt;	}
		else if constexpr (std::is_same_v<T, double>)		{ AssertReturnIf(m_Type != EVariantType::Double, T());	return m_Value.Double;	}
		else if constexpr (std::is_same_v<T, std::string>)	{ AssertReturnIf(m_Type != EVariantType::String, T());	return m_Value.String;	}
		else												{ Assert::Assert("Unsupported type"); return T(); }
	}
	
	template <typename T>
	const T& GetAs() const
	{
		if constexpr (std::is_same_v<T, bool>)				{ return *reinterpret_cast<const T*>(&m_Value.Bool);	}
		else if constexpr (std::is_same_v<T, int64_t>)		{ return *reinterpret_cast<const T*>(&m_Value.Int);	}
		else if constexpr (std::is_same_v<T, uint64_t>)		{ return *reinterpret_cast<const T*>(&m_Value.UInt);	}
		else if constexpr (std::is_same_v<T, double>)		{ return *reinterpret_cast<const T*>(&m_Value.Double);	}
		else if constexpr (std::is_same_v<T, std::string>)	{ return *reinterpret_cast<const T*>(&m_Value.String);	}
		else												{ Assert::Assert("Unsupported type"); return T(); }
	}

	bool				GetBool() const;
	int64_t				GetInt64() const;
	uint64_t			GetUInt64() const;
	double				GetDouble() const;
	const std::string&	GetString() const;

	bool				GetAsBool() const;
	int64_t				GetAsInt() const;
	uint64_t			GetAsUInt() const;
	double				GetAsDouble() const;
	const std::string&	GetAsString() const;

	static void Test();

private:
	void Destroy()
	{
		if (m_Type == EVariantType::String)
		{
			m_Value.String.~basic_string();
		}

		std::memset(&m_Value, 0, sizeof(ValueUnion));
		m_Type = EVariantType::Invalid;
	}

private:
	union ValueUnion
	{
		bool		Bool;
		int64_t		Int;
		uint64_t	UInt;
		double		Double;
		std::string String;

		ValueUnion() : Bool(false) {};
		~ValueUnion() {};
	};

	ValueUnion		m_Value;
	EVariantType	m_Type;
};