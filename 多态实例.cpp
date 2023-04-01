//
// Created by 刘日亮 on 2023/1/4.
//
#include <iostream>

using namespace std;
/*怪物之间可以互相攻击
 *怪物被攻击之后可以反击
 * Attack FightBack Hurted(int EnemyPower){ nLifeValue -= EnemyPower)
 * */
//一共有n个对象
//如果不用virtual，那么每个Creature都需要n个重载的 A F 函数

//如果添加一个对象，所有类都需要增加两个重载的 A F

/*多态的实现方法*/
//基类和派生类都需要virtual(同名虚函数）
class CCreatrure {
private://私有，不继承

protected://派生类函数中可以访问
    int m_nLifeValue, m_nPower;
public:
    virtual void HurtEd(int EnemyPower);

    virtual void Attack(CCreatrure *enemy);

    virtual void FightBack(CCreatrure *enemy);
};

class CDragon : public CCreatrure {
public:
    virtual void HurtEd(int EnemyPower);

    virtual void Attack(CCreatrure *enemy);

    virtual void FightBack(CCreatrure *enemy);
};

void CDragon::HurtEd(int EnemyPower) {
    m_nLifeValue -= EnemyPower;
}

void CDragon::Attack(CCreatrure *enemy) {
    enemy->HurtEd(m_nPower);
    enemy->FightBack(this);
}

void CDragon::FightBack(CCreatrure *enemy) {
    enemy->HurtEd(m_nPower / 2);
}

int main() {
    CDragon Dragon;
    CCreatrure A;
    CCreatrure B;

    Dragon.Attack(&A);
    return 0;
}
