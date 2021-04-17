#include "OpGetfield.h"

QByteArray OpGetfield::Compile()
{
	QByteArray code;
	QDataStream ds(&code, QIODevice::WriteOnly);

	ds << byteOpCode << (quint8)isStatic;

	if (isStatic)
	{
		ds << namespaceName << className << name;
	}
	else
	{
		ds << name;
	}

	return code;
}
