#pragma once

#include "StateManager.h"
#include "Updatable.h"
#include "Renderable.h"

#include <memory>

/// Singleton pattern without globals
class Prog : public Updatable, public Renderable
{
	private:

	public:
		Prog(); // creation possible only by getInstance, assert otherwise
		Prog(const Prog&) = delete;
		Prog& operator=(const Prog &) = delete;
		Prog(Prog &&) = delete;
		Prog & operator=(Prog &&) = delete;
		~Prog() = default;

		static Prog* getInstance();

		void update(float deltaTime) override;
		void render() override;
		void processInput(std::pair<unsigned, unsigned> touchAddress);

	private:
		static std::unique_ptr<Prog> s_progInstance;
		std::shared_ptr<StateManager> m_stateManager;
};
