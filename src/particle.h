#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <vector>
#include <array>
#include <string>

// -----------------------------------------------------------------------------------

class Particle{
		private:

		/* Veliciny castice */
		int particleID;
		int type; //0 castice tekutiny, 1 castice hranice
		double mass, rho, p;
		std::array<double, 2> position, velocity, velocity_last, acceleration;

		/* Interakce s ostatnimi casticemi */
		int num_of_neighbours; // pocet sousedu
		std::vector<int> list_of_neighbours; //list ID sousedu
		std::vector<std::array<double, 2>> neighbour_dist; // vzdalenost od sousedu
		std::vector<double> kernel_W;
		std::vector<double> kernel_dW_x;
		std::vector<double> kernel_dW_y;


		public:

		/* Konstruktory, destruktory */
		Particle(int, int, double, double, double, std::array<double,2>, std::array<double, 2>);
		Particle();
		~Particle();

		/* Metody - vypocet velicin */
		void Compute_density(std::vector<Particle> &particle_list, double mass, double W0);
		void Compute_d_density(std::vector<Particle> &particle_list, double mass, double W0);
		void Compute_pressure();
		void Compute_acceleration(std::vector<Particle> &particle_list, double mass, double h);

		/* Metody - ostatni, konstrolni */
		bool check_domain(std::array<double, 2>, int height_domain, int width_domain);
		void add_to_neighbours_list(int, double, double, double, std::array<double, 2>);
		void finish_step();
		void size_of_vectors();

		/* Settery, gettery */
		void set_position(std::array<double, 2>);
		std::array<double, 2> get_position();

		void set_velocity(std::array<double, 2>);
		std::array<double, 2> get_velocity();

		void set_velocity_last(std::array<double, 2>);
		std::array<double, 2> get_velocity_last();

		void set_acceleration(std::array<double, 2>);
		std::array<double, 2> get_acceleration();

		void set_mass(double m);
		double get_mass();

		void set_pressure(double p);
		double get_pressure();

		void set_density(double rho);
		auto get_density() -> double&;

		int get_type_of_particle();
		int get_ID_of_particle();

		int get_num_of_neighbours();

};

// -----------------------------------------------------------------------------------

class Particle_boundary: public Particle{

		//Particle_boundary(int, int, double, double, std::array<double,2>, std::array<double, 2>);
		//Particle_boundary();
		//~Particle_boundary();

		//Inheritence konstuktoru
		using Particle::Particle;

};

class Particle_fluid: public Particle{

		//Particle_fluid(int, int, double, double, std::array<double,2>, std::array<double, 2>);
		//Particle_fluid();
		//~Particle_fluid();

		//Inheritence konstuktoru
		using Particle::Particle;

};

class Particle_virtual: public Particle{

		//Particle_virtual(int, int, double, double, std::array<double,2>, std::array<double, 2>);
		//Particle_virtual();
		//~Particle_virtual();

		//Inheritence konstuktoru
		using Particle::Particle;

};

// -----------------------------------------------------------------------------------

#endif

