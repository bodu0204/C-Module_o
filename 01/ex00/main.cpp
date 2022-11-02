#include "Zombie.hpp"

int main(void)
{
    Zombie st("stack_zombie");
    Zombie* hp = newZombie("heap_zombie");
    
    randomChump("stack_zombie");
    st.announce();
    hp->announce();
    delete hp;
}