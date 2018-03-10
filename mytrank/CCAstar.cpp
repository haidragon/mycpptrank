#include "CCAstar.h"
//=====�Ż�����==================================================================================






CCAstar::PVIR_INFO CCAstar::m_pVir;





//=====�Ż�����==================================================================================

CCAstar::CCAstar()
{
}


CCAstar::~CCAstar()
{
}

void CCAstar::InitMapInfo(int* pMap, int nHigh, int nWidth, int nBlock)
{
	m_pMap = pMap;
	m_MapHigh = nHigh;
	m_MapWidth = nWidth;
	m_Block = nBlock;
	//=====�Ż�����==================================================================================






	m_pVir = new VIR_INFO[m_MapHigh*m_MapWidth]{};






	//=====�Ż�����==================================================================================

	m_bInitMapInfo = true;
}

void CCAstar::InitCoord(MYCOORD codStar, MYCOORD codEnd)
{
	m_Start = codStar;
	m_End = codEnd;
	m_bInitCoordInfo = true;
}

bool CCAstar::FindPath()
{
	//�Ƿ��ʼ�����
	if (!m_bInitCoordInfo || !m_bInitMapInfo)
	{
		return false;
	}
	/*
	1.  ��������걣�浽Open����
	2.1 �ж�Open���Ƿ�Ϊ�գ�����˵����·��ͬ
	2.2 �ҳ�Open����Fֵ��С�ĵ�
	2.3 ������ɢ
	2.4 ����ɢ�ĵ㱣�浽Close���У���Open����ɾ��
	2.5 �ж�����ɢ�����ĵ��Ƿ�ϸ�
	2.5.1 �Ƿ����յ㣬�Ǿ�ֱ�ӷ���
	�ǲ����ϰ���
	�ǲ���Խ��
	�Ƿ���Open����
	�Ƿ���Close����
	2.6 �Ѻϸ�ĵ���Open����
	2.7 �ظ�2.1 -- 2.6
	*/

	//���Open��Close��
	m_Open.clear();
	m_Close.clear();

	ZeroMemory(m_pVir, m_MapWidth *m_MapHigh);



	NODE_INFO nodeStar;
	nodeStar.codSelf = m_Start;
	nodeStar.g = 0;
	nodeStar.SetH_F(m_Start, m_End);

	m_Open.push_back(nodeStar);

	//��ʼѭ������

	while (true)
	{
		//Open���Ƿ�Ϊ��
		if (m_Open.empty())
		{
			return false;
		}
		//��Open����Fֵ��С�ĵ�
		int nIndex = 0;
		for (int i = 1; i < m_Open.size(); i++)
		{
			//�����ǰ��nIndex���� i�� ����
			if (m_Open[nIndex].f > m_Open[i].f)
			{
				nIndex = i;
			}
		}

		//����������С�ĵ���ɢ
		//��ɢ
		NODE_INFO nodeNew[4]{};

		//��
		nodeNew[0].codSelf.X = m_Open[nIndex].codSelf.X;
		nodeNew[0].codSelf.Y = m_Open[nIndex].codSelf.Y - 1;
		//��
		nodeNew[1].codSelf.X = m_Open[nIndex].codSelf.X;
		nodeNew[1].codSelf.Y = m_Open[nIndex].codSelf.Y + 1;
		//��
		nodeNew[2].codSelf.X = m_Open[nIndex].codSelf.X - 1;
		nodeNew[2].codSelf.Y = m_Open[nIndex].codSelf.Y;
		//��
		nodeNew[3].codSelf.X = m_Open[nIndex].codSelf.X + 1;
		nodeNew[3].codSelf.Y = m_Open[nIndex].codSelf.Y;

		for (int i = 0; i < 4; i++)
		{
			nodeNew[i].codParent = m_Open[nIndex].codSelf;
			nodeNew[i].g = m_Open[nIndex].g + 1;
			nodeNew[i].SetH_F(nodeNew[i].codSelf, m_End);
			//����
			nodeNew[i].codSelf.d = i;
		}
		//=====�Ż�����==================================================================================



		int x1 = m_Open[nIndex].codSelf.X;
		int y1 = m_Open[nIndex].codSelf.Y;
		m_pVir[y1 * m_MapWidth + x1].isClose = true;
		m_pVir[y1 * m_MapWidth + x1].isOpen  = false;




		//=====�Ż�����==================================================================================

		//����ɢ���ĵ㱣�浽Close������Open����ɾ��
		m_Close.push_back(m_Open[nIndex]);
		m_Open.erase(m_Open.begin() + nIndex);

		//�����ɢ�����ĵ��Ƿ�ϸ��Ƿ����յ�
		for (int i = 0; i < 4; i++)
		{
			int x = nodeNew[i].codSelf.X;
			int y = nodeNew[i].codSelf.Y;

			//�ǲ����յ�
			if (nodeNew[i].codSelf == m_End)
			{
				m_Close.push_back(nodeNew[i]);
				return true;
			}
			//�Ƿ�Խ��
			if (x <1 || y <1||
				x >(m_MapWidth) ||
				y >( m_MapHigh))
			{
				continue;
			}
			//�Ƿ����ϰ���
			/*if (m_pMap[y*m_MapWidth + x] == m_Block)
			{
				continue;
			}*/
		/*	if (m_pMap[y*m_MapWidth + x] == m_Block)
			{
				continue;
			}
		*/
			bool map = false;
			for (int i = x - 1; i <= x + 1; i++) {
				if (map) {
					break;
				}
				for (int j = y - 1; j <= y + 1; j++) {
					if (ccGlMap[i][j] == ZHANGAIMAP|| ccGlMap[i][j] == ZHANGAIMAP2) {
						map = true;
						break;
					}
				}
			}
			if (map) {
				map = false;
				continue;
			}

    
			//=====�Ż�����==================================================================================




			//�ж��Ƿ���Open���Close����
			if (m_pVir[y * m_MapWidth + x].isClose ||
				m_pVir[y * m_MapWidth + x].isOpen)
			{
				continue;
			}

			//=====�Ż�����==================================================================================


			//�Ƿ���Open����


			//=====û���Ż�����===========================================================================
			//bool bRet = false;
			//for (int o = 0; o < m_Open.size(); o++)
			//{
			//	if (nodeNew[i].codSelf == m_Open[o].codSelf)
			//	{
			//		bRet = true;
			//		break;
			//	}
			//}
			//if (bRet)
			//{
			//	continue;
			//}
			////�Ƿ���Close����
			//for (int o = 0; o < m_Close.size(); o++)
			//{
			//	if (nodeNew[i].codSelf == m_Close[o].codSelf)
			//	{
			//		bRet = true;
			//		break;
			//	}
			//}
			//if (bRet)
			//{
			//	continue;
			//}
			//=====û���Ż�����================================================================================




			//���ϸ�ĵ㱣�浽Open����
			m_Open.push_back(nodeNew[i]);




			//=====�Ż�����=====================================================================================



			m_pVir[y * m_MapWidth + x].isOpen = true;




			//=====�Ż�����=====================================================================================
		}

	}//while
}

void CCAstar::GetPath()
{
	//���ݸ��ڵ�
	m_Path.clear();//���ԭ����·��
	int nSize = m_Close.size();
	int nIndex = nSize - 1;

	while (true)
	{
		for (int i = 0; i < nSize; i++)
		{
			if (m_Close[nIndex].codParent == m_Start)
			{
				return;
			}
			if (m_Close[nIndex].codParent == m_Close[i].codSelf)
			{
				m_Path.push_back(m_Close[i].codSelf);
				nIndex = i;
				break;
			}
		}
	}
}


void CCAstar::PrintPath()
{
	for (int i = m_Path.size() - 1; i >= 0; i--)
	{
		PrintChar(m_Path[i].X, m_Path[i].Y, "@", 10);
	}
}
void CCAstar::PrintChar(int x, int y, char* pStr, short color)
{
	DWORD dwWrite;
	COORD pos = { x * 2, y };
	int nLen = strlen(pStr);
	WORD* pColor = new WORD[nLen * 2];
	wmemset((wchar_t*)pColor, color, nLen * 2);
	WriteConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), pColor, nLen * 2, pos, &dwWrite);
	WriteConsoleOutputCharacterA(GetStdHandle(STD_OUTPUT_HANDLE), pStr, nLen, pos, &dwWrite);
	delete[] pColor;
	pColor = nullptr;
}



//����̹��
//�Ƿ����ϰ���

//if (((ccGlMap[2 + x][ y] == QANGMAP || ccGlMap[1 +  x][-1 +  y] == QANGMAP || ccGlMap[1 +  x][1 +  y] == QANGMAP) && nodeNew[i].codSelf.d == TANK_DIR_RH) ||
//	((ccGlMap[-2 +  x][ y] == QANGMAP || ccGlMap[-1 +  x][-1 +  y] == QANGMAP || ccGlMap[-1 +  x][1 +  y] == QANGMAP) && nodeNew[i].codSelf.d == TANK_DIR_LF) ||
//	((ccGlMap[ x][2 +  y] == QANGMAP || ccGlMap[1 +  x][1 +  y] == QANGMAP || ccGlMap[-1 +  x][1 +  y] == QANGMAP) && nodeNew[i].codSelf.d == TANK_DIR_DW) ||
//	((ccGlMap[ x][-2 +  y] == QANGMAP || ccGlMap[-1 +  x][-1 +  y] == QANGMAP || ccGlMap[1 +  x][-1 +  y] == QANGMAP) && nodeNew[i].codSelf.d == TANK_DIR_UP)
//	
//	/*	||
//	((ccGlMap[2 +  x][ y] == ENEMYTANKMAP || ccGlMap[1 +  x][-1 +  y] == ENEMYTANKMAP || ccGlMap[1 +  x][1 +  y] == ENEMYTANKMAP) &&  dir == TANK_DIR_RH) ||
//	((ccGlMap[-2 +  x][ y] == ENEMYTANKMAP || ccGlMap[-1 +  x][-1 +  y] == ENEMYTANKMAP || ccGlMap[-1 +  x][1 +  y] == ENEMYTANKMAP) &&  dir == TANK_DIR_LF) ||
//	((ccGlMap[ x][2 +  y] == ENEMYTANKMAP || ccGlMap[1 +  x][1 +  y] == ENEMYTANKMAP || ccGlMap[-1 +  x][1 +  y] == ENEMYTANKMAP) &&  dir == TANK_DIR_DW) ||
//	((ccGlMap[ x][-2 +  y] == ENEMYTANKMAP || ccGlMap[-1 +  x][-1 +  y] == ENEMYTANKMAP || ccGlMap[1 +  x][-1 +  y] == ENEMYTANKMAP) &&  dir == TANK_DIR_UP)
//	*/
//	)
//{
//	continue;
//}
//    