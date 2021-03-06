/*
 * CodificadorMensajes.h
 *
 *  Created on: Apr 2, 2016
 *      Author: gonzalo
 */

#ifndef SRC_SERVER_ALANTURING_H_
#define SRC_SERVER_ALANTURING_H_

#include "../Utils/Logger.h"
#include "../Utils/TiposDefinidos.h"
#include <string>
#include <cstring>
#include <stdio.h>

/*
 * Message Codes
 *
 *int: envia nun entero
 *chr: envia un char
 *dbl: envia un double
 *str: envia un string
 *cnt: cliente conectado
 *ext: pide el cierre del receptor
 *ful: servidor lleno
 */
/*
 * Message Status
 *
 * - : no procesado
 * I : mensaje procesado e Invalido
 * V : mensaje procesado y Valido
 */

class AlanTuring
{
public:
	//ENCODES Y DECODES RELACIONADOS AL JUEGO
	int encodeDrawMessage(DrawMessage msj, char* bufferSalida);
	int encodeInputMessage(InputMessage msj, char* bufferSalida);

	DrawMessage decodeDrawMessage(NetworkMessage netMsg);
	InputMessage decodeInputMessage(NetworkMessage netMsg);

	//devuelve un buffer de 256 bytes con el mensaje codificado en binario en buffeSalida y un int con el tamaño Mensaje
	int encodeXMLMessage(Mensaje mensaje, char* bufferSalida);
	int encodeNetworkMessage(NetworkMessage netMsg, char* bufferSalida);

	//los decode reciben buffers de tamaño 256
	NetworkMessage decode (char* codigoEnigma);
	unsigned short decodeLength(char* codigoEnigma);
	DataMessage decodeMessage (NetworkMessage netMsg);

	//modificadores de NetworkMessage
	void changeDataValue(NetworkMessage* networkMessage, std::string& newValue);
	void setNetworkMessageStatus(NetworkMessage* networkMessage, char statusCode);

	/*intMessage decodeIntMessage(char* datosCodigoEnigma);
	charMessage decodeCharMessage(char* datosCodigoEnigma);
	doubleMessage decodeDoubleMessage(char* datosCodigoEnigma);
	stringMessage decodeStringMessage(char* datosCodigoEnigma);*/

	AlanTuring();
	~AlanTuring();

private:
	//llena los campos de netMsg con la información del mensaje
	void fillMsgData(NetworkMessage* netMsg, const Mensaje mensaje);

	void encodeMessage(NetworkMessage* netMsg, const Mensaje mensaje);

	/*void encodeIntMessage(NetworkMessage* netMsg, const Mensaje mensaje);
	void encodeCharMessage(NetworkMessage* netMsg, const Mensaje mensaje);
	void encodeDoubleMessage(NetworkMessage* netMsg, const Mensaje mensaje);
	void encodeStringMessage(NetworkMessage* netMsg, const Mensaje mensaje);*/
};

#endif /* SRC_SERVER_ALANTURING_H_ */
