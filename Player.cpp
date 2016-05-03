/*
 * Player.cpp
 *
 *  Created on: Apr 9, 2016
 *      Author: gonzalo
 */

#include "Player.h"

using namespace std;

Player::Player() :  MoveableObject(),
					m_controllable(true),
					m_dead(false),
					m_dying(false)
{
	m_tag = "Player";
}

Player::Player(bool canControl) :  MoveableObject(),
									m_dead(false),
									m_dying(false)
{
	m_controllable = canControl;
	m_tag = "Player";
}

void Player::collision()
{

}

void Player::load(int x, int y, int width, int height, int textureID, int numFrames)
{
    // Load comun. Inicializa variables
    MoveableObject::load(x, y, width, height, textureID, numFrames);

    TextureManager::Instance()->load("Assets/Sprites/BlackShip.png", m_textureID, Game::Instance()->getRenderer());

    // Otras acciones de inicialización del Player más especificas

}

void Player::draw()
{
    TextureManager::Instance()->drawFrame(m_textureID, m_position.getX(), m_position.getY(), m_width, m_height,
    										m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), m_angle, m_alpha, SDL_FLIP_NONE);
	//Nave::draw();
}

void Player::update()
{
	MoveableObject::update();
	//Probar valores para animacion
	//m_currentFrame = int(((SDL_GetTicks() / (1000 / 3)) % m_numFrames));
}


void Player::clean()
{
    MoveableObject::clean();
}

void Player::handleInput()
{
	InputMessage mensaje;

	mensaje.buttonUp=0;
	mensaje.buttonDown=0;
	mensaje.buttonRight=0;
	mensaje.buttonLeft=0;
	mensaje.buttonShoot=0;
	mensaje.buttonReserved=0;//2 bytes reserved for future
	mensaje.buttonShootNigaPower=0;
	mensaje.buttonXpecialCombo=0;
	mensaje.buttonCompressionSistem=0;
	mensaje.actionID=0;

	// handle keys
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
	{
		mensaje.buttonShoot=1;
	}
	if (((InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) || (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_W))))
	{
		mensaje.buttonUp = 1;
	}

	if (((InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) || (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_S))))
	{
		mensaje.buttonDown = 1;
	}

	if (((InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) || (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))))
	{
		mensaje.buttonLeft = 1;
	}
	if (((InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) || (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_D))))
	{
		mensaje.buttonRight = 1;
	}

	Game::Instance()->sendToKorea( mensaje);
}