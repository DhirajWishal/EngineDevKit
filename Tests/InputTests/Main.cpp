#include "Inputs/Suppliers/KeyInputSupplier.h"
#include "Inputs/Suppliers/MouseInputSupplier.h"

class DisplayHandle :
	public EDK::Inputs::KeyInputSupplier,
	public EDK::Inputs::MouseInputSupplier {
public:
	DisplayHandle() {}
	~DisplayHandle() {}

	virtual void EDK::Inputs::KeyInputSupplier::OnInitializeSupplier() override final
	{

	}

	//virtual void EDK::Inputs::MouseInputSupplier::OnInitializeSupplier() override final
	//{
	//
	//}
};

int main()
{

}