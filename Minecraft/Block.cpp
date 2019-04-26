#include "pch.h"
#include "Block.h"
#include "Map.h"
#include "game_constants.h"
#include "block_db.h"

using std::array;
using namespace World;

Block::Block(World::Map *world) 
{
	m_world = world;
}

Block::~Block()
{
}

void Block::bind_textures(DB::block_id id, const sf::Vector3f &pos)
{
	const array<GLuint, 6> &box = DB::blocks_db[id];

	float half_size = BLOCK_SIZE / 2;
	const float d_x = BLOCK_SIZE*(pos.x),
				d_y = BLOCK_SIZE*(pos.y),
				d_z = BLOCK_SIZE*(pos.z);

	if (!m_world->is_block(pos.x, pos.y, pos.z - 1)) {
		glBindTexture(GL_TEXTURE_2D, box[0]);
		glBegin(GL_QUADS);
		//front
		glTexCoord2f(0, 0);   glVertex3f( - half_size + d_x,  - half_size + d_y,  - half_size + d_z);
		glTexCoord2f(1, 0);   glVertex3f( + half_size + d_x,  - half_size + d_y,  - half_size + d_z);
		glTexCoord2f(1, 1);   glVertex3f( + half_size + d_x,  + half_size + d_y,  - half_size + d_z);
		glTexCoord2f(0, 1);   glVertex3f( - half_size + d_x,  + half_size + d_y,  - half_size + d_z);
		glEnd();
	}

	if (!m_world->is_block(pos.x, pos.y, pos.z + 1)) {
		glBindTexture(GL_TEXTURE_2D, box[1]);
		glBegin(GL_QUADS);
		//back
		glTexCoord2f(0, 0); glVertex3f( + half_size + d_x,  - half_size + d_y,  + half_size + d_z);
		glTexCoord2f(1, 0); glVertex3f( - half_size + d_x,  - half_size + d_y,  + half_size + d_z);
		glTexCoord2f(1, 1); glVertex3f( - half_size + d_x,  + half_size + d_y,  + half_size + d_z);
		glTexCoord2f(0, 1); glVertex3f( + half_size + d_x,  + half_size + d_y,  + half_size + d_z);
		glEnd();
	}

	if (!m_world->is_block(pos.x - 1, pos.y, pos.z)) {
		glBindTexture(GL_TEXTURE_2D, box[2]);
		glBegin(GL_QUADS);
		//left
		glTexCoord2f(0, 0); glVertex3f( - half_size + d_x,  - half_size + d_y,  + half_size + d_z);
		glTexCoord2f(1, 0); glVertex3f( - half_size + d_x,  - half_size + d_y,  - half_size + d_z);
		glTexCoord2f(1, 1); glVertex3f( - half_size + d_x,  + half_size + d_y,  - half_size + d_z);
		glTexCoord2f(0, 1); glVertex3f( - half_size + d_x,  + half_size + d_y,  + half_size + d_z);
		glEnd();
	}

	if (!m_world->is_block(pos.x + 1, pos.y, pos.z)) {
		glBindTexture(GL_TEXTURE_2D, box[3]);
		glBegin(GL_QUADS);
		//right
		glTexCoord2f(0, 0); glVertex3f( + half_size + d_x,  - half_size + d_y,  - half_size + d_z);
		glTexCoord2f(1, 0); glVertex3f( + half_size + d_x,  - half_size + d_y,  + half_size + d_z);
		glTexCoord2f(1, 1); glVertex3f( + half_size + d_x,  + half_size + d_y,  + half_size + d_z);
		glTexCoord2f(0, 1); glVertex3f( + half_size + d_x,  + half_size + d_y,  - half_size + d_z);
		glEnd();
	}

	if (!m_world->is_block(pos.x, pos.y - 1, pos.z)) {
		glBindTexture(GL_TEXTURE_2D, box[4]);
		glBegin(GL_QUADS);
		//bottom
		glTexCoord2f(0, 0); glVertex3f( - half_size + d_x,  - half_size + d_y,  + half_size + d_z);
		glTexCoord2f(1, 0); glVertex3f( + half_size + d_x,  - half_size + d_y,  + half_size + d_z);
		glTexCoord2f(1, 1); glVertex3f( + half_size + d_x,  - half_size + d_y,  - half_size + d_z);
		glTexCoord2f(0, 1); glVertex3f( - half_size + d_x,  - half_size + d_y,  - half_size + d_z);
		glEnd();
	}

	if (!m_world->is_block(pos.x, pos.y + 1, pos.z)) {
		glBindTexture(GL_TEXTURE_2D, box[5]);
		glBegin(GL_QUADS);
		//top  		
		glTexCoord2f(0, 0); glVertex3f( - half_size + d_x,  + half_size + d_y,  - half_size + d_z);
		glTexCoord2f(1, 0); glVertex3f( + half_size + d_x,  + half_size + d_y,  - half_size + d_z);
		glTexCoord2f(1, 1); glVertex3f( + half_size + d_x,  + half_size + d_y,  + half_size + d_z);
		glTexCoord2f(0, 1); glVertex3f( - half_size + d_x,  + half_size + d_y,  + half_size + d_z);
		glEnd();
	}
}
