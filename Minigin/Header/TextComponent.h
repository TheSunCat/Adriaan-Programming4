#pragma once
#include <memory>
#include <string>

#include "Component.h"
#include "TextureComponent.h"
#include "Header\Font.h"
#include "Header\Texture2D.h"

namespace dae
{

	class TextComponent final : public Component
	{
	public:
		TextComponent(const std::string& textToDisplay, const std::string& fontPath, unsigned int size);
		~TextComponent() override = default;
	
		TextComponent(const TextComponent&) = delete;
		TextComponent& operator= (const TextComponent&) = delete;
		TextComponent(TextComponent&&) = delete;
		TextComponent& operator= (const TextComponent&&) = delete;
	
		void Update() override;
		void Render() const override;
		
		void SetPosition(float x, float y, float z = 0);

		void SetText(const std::string& textToDisplay);
	private:
		std::unique_ptr<TransformComponent> m_TransformUPtr;

		bool m_NeedsUpdate;
		std::string m_Text;
		std::shared_ptr<dae::Font> m_FontUPtr;
		std::unique_ptr<dae::Texture2D> m_TextTextureSPtr;
	};

}