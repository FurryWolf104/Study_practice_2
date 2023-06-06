#include <iostream>
#include <vector>

using namespace std;

int main()
{
    setlocale(0, "Rus");
    vector<vector<double>> a;
    int n;

    cout << "������� ���������� ���������: ";
    cin >> n;

    a.resize(n, vector<double>(n + 1));

    for (int i = 0; i < n; i++) {
        cout << "������� ������������ ��������� " << i + 1 << ": ";
        for (int j = 0; j < n + 1; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        double pivot = a[i][i];

        // ���� ������� ������� ����� ����, ������ ������ �������, ����� �������� ������� �� ����
        if (pivot == 0) {
            for (int k = i + 1; k < n; k++) {
                if (a[k][i] != 0) {
                    for (int j = i; j < n + 1; j++) {
                        swap(a[i][j], a[k][j]);
                    }
                    pivot = a[i][i];
                    break;
                }
            }
        }

        // ���� ��� ��������� �������� � ���� ������� ����� ����, ��������� � ���������� �������
        if (pivot == 0) {
            continue;
        }

        // ����������� ������� ������
        for (int j = i; j < n + 1; j++) {
            a[i][j] /= pivot;
        }

        // �������� ������� ������� ������ �� ���� ��������� �����
        for (int k = 0; k < n; k++) {
            if (k == i) {
                continue;
            }
            double factor = a[k][i];
            for (int j = i; j < n + 1; j++) {
                a[k][j] -= factor * a[i][j];
            }
        }
    }

    cout << "������� �������: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i << " = " << a[i][n] << endl;
    }

    return 0;
}