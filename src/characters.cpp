#include "headers/characters.hpp"

// void Characters::alloc_chars()
// {
// 	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

// 	for (GLubyte c = 0; c < 128; c++) {
// 		FT_Load_Char(face, c, FT_LOAD_RENDER);

// 		GLuint texture;
// 		glCreateTextures(GL_TEXTURE_2D,1, &texture);
// 		glTextureStorage2D(texture, 1, GL_R8, face->glyph->bitmap.width, face->glyph->bitmap.rows);
// 		glTextureSubImage2D(texture, 0, 0, 0, face->glyph->bitmap.width, face->glyph->bitmap.rows, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);

// 		glBindTexture(GL_TEXTURE_2D, texture);
// 		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
// 		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
// 		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
// 		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
// 		glBindTexture(GL_TEXTURE_2D, 0);

// 		Character character = {
// 			texture,
// 			glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
// 			glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
// 			face->glyph->advance.x
// 		};
		
// 		characters.insert(std::pair<GLchar, Character>(c, character));
// 	}

// 	FT_Done_Face(face);
// 	FT_Done_FreeType(ft);

// 	projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f);
// }