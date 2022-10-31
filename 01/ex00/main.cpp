#include "Zombie.hpp"

int main(void)
{
    Zombie st("stack_zombie");
    Zombie* hp = newZombie("heap_zombie");
    
    st.randomChump("stack_zombie");
    hp->randomChump("heap_zombie");
    st.announce();
    hp->announce();
    delete hp;
}