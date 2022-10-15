#include "./Zombie.hpp"

int main(void)
{
    Zombie st("stack_zombie");
    Zombie* hp = Zombie::newZombie("heap_zombie");
    
    st.announce();
    hp->announce();
    delete hp;
}