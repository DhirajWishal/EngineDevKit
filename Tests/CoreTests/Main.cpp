// Copyright 2020 Dhiraj Wishal
// SPDX-License-Identifier: Apache-2.0
#include <memory>

int main()
{
	std::unique_ptr<int> pRef = std::make_unique<int>(1000);
	pRef.get();

	delete pRef.release();
}