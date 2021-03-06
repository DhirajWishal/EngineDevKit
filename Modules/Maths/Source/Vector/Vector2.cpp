// Copyright 2020 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0

#include "Maths/Vector/Vector2.h"
#include "ErrorHandler/Logger.h"
#include "Memory/Functions.h"
#include "Core/Types/Utilities.h"

namespace EDK
{
	namespace Maths
	{
		Vector2::Vector2(std::initializer_list<float> list)
			: x(0.0f), y(0.0f)
		{
			if ((list.size() > 2) || (list.size() < 2))
				ErrorHandler::Logger::LogError(TEXT("The size of the provided list does not match the current Vector size! Expected size is 2."));

			Memory::MoveData(this, Cast<const void*>(list.begin()), list.size() * sizeof(float));
		}

		Vector2 Vector2::operator=(const std::initializer_list<float>& list)
		{
			if ((list.size() > 2) || (list.size() < 2))
				ErrorHandler::Logger::LogError(TEXT("The size of the provided list does not match the current Vector size! Expected size is 2."));

			Memory::MoveData(this, Cast<const void*>(list.begin()), list.size() * sizeof(float));

			return *this;
		}

		const float Vector2::operator[](UI32 index) const
		{
			return (operator const float* ())[index];
		}

		float& Vector2::operator[](UI32 index)
		{
			return const_cast<float&>((operator const float* ())[index]);
		}

		Vector2::operator const float* () const
		{
			return &this->x;
		}

		Vector2 operator+(const Vector2& lhs, const Vector2& rhs)
		{
			return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
		}

		Vector2 operator-(const Vector2& lhs, const Vector2& rhs)
		{
			return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
		}

		Vector2 operator*(const Vector2& lhs, const Vector2& rhs)
		{
			return Vector2(lhs.x * rhs.x, lhs.y * rhs.y);
		}

		Vector2 operator/(const Vector2& lhs, const Vector2& rhs)
		{
			return Vector2(lhs.x / rhs.x, lhs.y / rhs.y);
		}

		Vector2 operator+(const Vector2& lhs, const float& value)
		{
			return lhs + Vector2(value);
		}

		Vector2 operator-(const Vector2& lhs, const float& value)
		{
			return lhs - Vector2(value);
		}

		Vector2 operator*(const Vector2& lhs, const float& value)
		{
			return lhs * Vector2(value);
		}

		Vector2 operator/(const Vector2& lhs, const float& value)
		{
			return lhs / Vector2(value);
		}

		bool operator==(const Vector2& lhs, const Vector2& rhs)
		{
			return (lhs.x == rhs.x) && (lhs.y == rhs.y);
		}

		bool operator!=(const Vector2& lhs, const Vector2& rhs)
		{
			return (lhs.x != rhs.x) || (lhs.y != rhs.y);
		}

		bool operator<(const Vector2& lhs, const Vector2& rhs)
		{
			return (lhs.x < rhs.x) || (lhs.y < rhs.y);
		}

		bool operator<=(const Vector2& lhs, const Vector2& rhs)
		{
			return (lhs.x <= rhs.x) || (lhs.y <= rhs.y);
		}

		bool operator>(const Vector2& lhs, const Vector2& rhs)
		{
			return (lhs.x > rhs.x) || (lhs.y > rhs.y);
		}

		bool operator>=(const Vector2& lhs, const Vector2& rhs)
		{
			return (lhs.x >= rhs.x) || (lhs.y >= rhs.y);
		}

		bool operator&&(const Vector2& lhs, const Vector2& rhs)
		{
			return (lhs.x && rhs.x) && (lhs.y && rhs.y);
		}

		bool operator||(const Vector2& lhs, const Vector2& rhs)
		{
			return (lhs.x || rhs.x) || (lhs.y || rhs.y);
		}

		bool operator^(const Vector2& lhs, const Vector2& rhs)
		{
			return (lhs.x || rhs.x) && (lhs.y || rhs.y);
		}

		bool operator~(const Vector2& rhs)
		{
			return (rhs.x > 0) && (rhs.y > 0);
		}

		bool operator!(const Vector2& rhs)
		{
			return (rhs.x != 0) && (rhs.y != 0);
		}
	}
}