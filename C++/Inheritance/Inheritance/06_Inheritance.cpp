// 상속 봉인 : final
// 클래스명 뒤에 final 키워드를 작성한다면 해당 형식의 파생클래스가 생성되지 못하도록 합니다.

class BaseClass final {};

// final 키워드를 작성한 클래스를 통하여 파생 클래스를 생성하고 있으므로 오류가 나타납니다.
class DerivedClass : public BaseClass {};
