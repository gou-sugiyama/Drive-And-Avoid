#pragma once
//タイトルの管理
class CTitle :
    public CScene
{
private:
public:
    CTitle(CController* pController) ;
    ~CTitle() {}

    CScene* Update() override;
    void Render()const override;
};

